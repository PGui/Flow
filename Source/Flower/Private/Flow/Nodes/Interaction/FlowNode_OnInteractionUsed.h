#pragma once

#include "FlowNode_InteractionBase.h"
#include "FlowNode_OnInteractionUsed.generated.h"

class UFlowComponent;
class UInteractionComponent;

/**
 * On Interaction Used
 */
UCLASS(meta = (DisplayName = "On Interaction Used"))
class UFlowNode_OnInteractionUsed final : public UFlowNode_InteractionBase
{
	GENERATED_UCLASS_BODY()
	
private:
	TMap<TWeakObjectPtr<AActor>, TWeakObjectPtr<UInteractionComponent>> ObservedInteractions;

protected:
	virtual void ExecuteInput(const FName& PinName) override;

private:
	UFUNCTION()
	void OnComponentRegistered(UFlowComponent* Component);

	UFUNCTION()
	void OnComponentUnregistered(UFlowComponent* Component);

	void ObserveInteractionInActor(TWeakObjectPtr<AActor> Actor);
	
	UFUNCTION()
	void OnInteractionUsed();

protected:
	virtual void Cleanup() override;
};
