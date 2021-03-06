#include "Nodes/Route/FlowNode_CustomEvent.h"

UFlowNode_CustomEvent::UFlowNode_CustomEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Route");
	NodeStyle = EFlowNodeStyle::InOut;
#endif

	InputNames.Empty();
}

void UFlowNode_CustomEvent::ExecuteInput(const FName& PinName)
{
	TriggerFirstOutput(true);
}

#if WITH_EDITOR
FString UFlowNode_CustomEvent::GetNodeDescription() const
{
	return EventName.ToString();
}
#endif
