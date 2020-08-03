#include "FlowNode_OnInteractionUsed.h"
#include "Components/InteractionComponent.h"

#include "FlowComponent.h"
#include "FlowSubsystem.h"

UFlowNode_OnInteractionUsed::UFlowNode_OnInteractionUsed(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	NodeStyle = EFlowNodeStyle::Condition;
#endif

	OutputNames = { TEXT("Used") };
}

void UFlowNode_OnInteractionUsed::ExecuteInput(const FName& PinName)
{
	for (const TWeakObjectPtr<AActor> FoundActor : GetFlowSubsystem()->GetActors<AActor>(IdentityTag))
	{
		ObserveInteractionInActor(FoundActor);
	}

	GetFlowSubsystem()->OnComponentRegistered.AddDynamic(this, &UFlowNode_OnInteractionUsed::OnComponentRegistered);
	GetFlowSubsystem()->OnComponentUnregistered.AddDynamic(this, &UFlowNode_OnInteractionUsed::OnComponentUnregistered);
}

void UFlowNode_OnInteractionUsed::OnComponentRegistered(UFlowComponent* Component)
{
	if (Component->IdentityTags.HasTagExact(IdentityTag))
	{
		ObserveInteractionInActor(Component->GetOwner());
	}
}

void UFlowNode_OnInteractionUsed::OnComponentUnregistered(UFlowComponent* Component)
{
	if (ObservedInteractions.Contains(Component->GetOwner()) && Component->IdentityTags.HasTagExact(IdentityTag))
	{
		ObservedInteractions[Component->GetOwner()]->OnUsed.RemoveAll(this);
		ObservedInteractions.Remove(Component->GetOwner());
	}
}

void UFlowNode_OnInteractionUsed::ObserveInteractionInActor(TWeakObjectPtr<AActor> Actor)
{
	if (!ObservedInteractions.Contains(Actor))
	{
		TArray<UInteractionComponent*> FoundInteractions;
		Actor->GetComponents<UInteractionComponent>(FoundInteractions);
		
		if (FoundInteractions.Num() > 0)
		{
			ObservedInteractions.Emplace(Actor, FoundInteractions[0]);
			FoundInteractions[0]->OnUsed.AddDynamic(this, &UFlowNode_OnInteractionUsed::OnInteractionUsed);
		}
	}
}

void UFlowNode_OnInteractionUsed::OnInteractionUsed()
{
	TriggerFirstOutput(true);
}

void UFlowNode_OnInteractionUsed::Cleanup()
{
	for (const TPair<TWeakObjectPtr<AActor>, TWeakObjectPtr<UInteractionComponent>>& Interaction : ObservedInteractions)
	{
		Interaction.Value->OnUsed.RemoveAll(this);
	}
	ObservedInteractions.Empty();
}
