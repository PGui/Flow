#include "FlowNode_SimpleSpawn.h"
#include "FlowSubsystem.h"

UFlowNode_SimpleSpawn::UFlowNode_SimpleSpawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("World");
#endif

	InputNames = { TEXT("Spawn"), TEXT("Despawn") };
	OutputNames = { TEXT("Out"), TEXT("Spawned"), TEXT("Despawned") };
}

void UFlowNode_SimpleSpawn::ExecuteInput(const FName& PinName)
{
	if (IdentityTag.IsValid())
	{
		if (PinName == TEXT("Spawn"))
		{
			for (const TWeakObjectPtr<UFlowComponent>& FoundComponent : GetFlowSubsystem()->GetComponents<UFlowComponent>(IdentityTag))
			{
				TArray<USpawnComponent*> NewSpawnComponents;
				FoundComponent->GetOwner()->GetComponents<USpawnComponent>(NewSpawnComponents);

				for (USpawnComponent* SpawnComponent : NewSpawnComponents)
				{
					if (!SpawnComponents.Contains(SpawnComponent))
					{
						SpawnComponents.Emplace(SpawnComponent);
						SpawnComponent->Spawn(SpawnParams);
					}
				}
			}

			TriggerOutput(TEXT("Spawned"));
		}
		else if (PinName == TEXT("Despawn"))
		{
			for (TWeakObjectPtr<USpawnComponent> SpawnComponent : SpawnComponents)
			{
				if (SpawnComponent.IsValid())
				{
					SpawnComponent->Despawn();
				}
			}

			TriggerOutput(TEXT("Despawned"), true);
		}
	}
	else
	{
		LogError(MissingIdentityTag);
	}

	TriggerFirstOutput(true);
}

void UFlowNode_SimpleSpawn::Cleanup()
{
	SpawnComponents.Empty();
}

#if WITH_EDITOR 
FString UFlowNode_SimpleSpawn::GetNodeDescription() const
{
	const FString IdentityString = IdentityTag.IsValid() ? IdentityTag.ToString() : MissingIdentityTag;
	const FString ClassString = SpawnParams.ActorClass ? SpawnParams.ActorClass->GetFName().ToString() : TEXT("Missing Actor Class!");

	return IdentityString + LINE_TERMINATOR + ClassString;
}
#endif
