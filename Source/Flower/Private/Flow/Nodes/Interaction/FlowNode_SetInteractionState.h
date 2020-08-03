#pragma once

#include "FlowNode_InteractionBase.h"
#include "FlowNode_SetInteractionState.generated.h"

/**
 * Set Interaction State
 */
UCLASS(meta = (DisplayName = "Set Interaction State"))
class UFlowNode_SetInteractionState final : public UFlowNode_InteractionBase
{
	GENERATED_UCLASS_BODY()
	
protected:
	virtual void ExecuteInput(const FName& PinName) override;
};
