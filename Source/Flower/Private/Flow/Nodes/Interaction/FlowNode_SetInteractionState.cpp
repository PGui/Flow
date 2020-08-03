#include "FlowNode_SetInteractionState.h"
#include "Components/InteractionComponent.h"

#include "FlowSubsystem.h"

UFlowNode_SetInteractionState::UFlowNode_SetInteractionState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InputNames = { TEXT("Enable"), TEXT("Disable") };
}

void UFlowNode_SetInteractionState::ExecuteInput(const FName& PinName)
{
	for (const TWeakObjectPtr<AActor> FoundActor : GetFlowSubsystem()->GetActors<AActor>(IdentityTag))
	{
		TArray<UInteractionComponent*> FoundInteractions;
		FoundActor->GetComponents<UInteractionComponent>(FoundInteractions);
		if (FoundInteractions.Num() > 0)
		{
			if (PinName == TEXT("Enable"))
			{
				FoundInteractions[0]->Enable();
			}
			else
			{
				FoundInteractions[0]->Disable();
			}
		}
	}

	TriggerFirstOutput(true);
}
