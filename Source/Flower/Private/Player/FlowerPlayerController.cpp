#include "Player/FlowerPlayerController.h"
#include "FlowerSettings.h"

#include "Components/InteractionComponent.h"
#include "UI/FlowerUIManager.h"

AFlowerPlayerController::AFlowerPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	UInteractionComponent::OnPlayerEnter.AddUObject(this, &AFlowerPlayerController::OnInteractionEnter);
	UInteractionComponent::OnPlayerExit.AddUObject(this, &AFlowerPlayerController::OnInteractionExit);
}

void AFlowerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Interaction", IE_Released, this, &AFlowerPlayerController::OnInteractionUsed);
}

void AFlowerPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (PossibleInteractions.Num() > 0)
	{
		const FVector CameraLocation = PlayerCameraManager->GetCameraLocation();
		PossibleInteractions.Sort([CameraLocation](const TWeakObjectPtr<UInteractionComponent>& A, const TWeakObjectPtr<UInteractionComponent>& B)
		{
			const float DistanceA = FVector::DistSquared(CameraLocation, A.Get()->GetComponentLocation());
			const float DistanceB = FVector::DistSquared(CameraLocation, B.Get()->GetComponentLocation());
			return DistanceA < DistanceB;
		});

		if (!ActiveInteraction.IsValid() && ActiveInteraction != PossibleInteractions[0])
		{
			ActivateInteraction(PossibleInteractions[0]);
		}
	}
	else if (ActiveInteraction.IsValid())
	{
		DectivateInteraction();
	}
}

void AFlowerPlayerController::OnInteractionEnter(const TWeakObjectPtr<UInteractionComponent> Interaction)
{
	PossibleInteractions.Add(Interaction);
}

void AFlowerPlayerController::OnInteractionExit(const TWeakObjectPtr<UInteractionComponent> Interaction)
{
	if (ActiveInteraction.IsValid() && ActiveInteraction == Interaction)
	{
		DectivateInteraction();
	}
	
	PossibleInteractions.Remove(Interaction);
}

void AFlowerPlayerController::ActivateInteraction(const TWeakObjectPtr<UInteractionComponent> Interaction)
{
	if (ActiveInteraction.IsValid())
	{
		DectivateInteraction();
	}
	
	ActiveInteraction = Interaction;
	GetGameInstance()->GetSubsystem<UFlowerUIManager>()->ToggleWidget(UFlowerSettings::Get()->InteractionWidget);
}	

void AFlowerPlayerController::DectivateInteraction()
{
	ActiveInteraction = nullptr;
	GetGameInstance()->GetSubsystem<UFlowerUIManager>()->ToggleWidget(UFlowerSettings::Get()->InteractionWidget);
}

void AFlowerPlayerController::OnInteractionUsed()
{
	if (ActiveInteraction.IsValid())
	{
		ActiveInteraction->OnUsed.Broadcast();
	}
}
