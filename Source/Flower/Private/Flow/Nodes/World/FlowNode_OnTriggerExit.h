#pragma once

#include "FlowNode_OnTriggerEvent.h"
#include "FlowNode_OnTriggerExit.generated.h"

/**
 * On Trigger Exit
 */
UCLASS(meta = (DisplayName = "On Trigger Exit"))
class UFlowNode_OnTriggerExit final : public UFlowNode_OnTriggerEvent
{
	GENERATED_UCLASS_BODY()
};
