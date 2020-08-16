#pragma once

#include "Nodes/World/FlowNode_ComponentObserver.h"
#include "FlowNode_OnInteractionUsed.generated.h"

class UFlowComponent;
class UInteractionComponent;

/**
 * On Interaction Used
 */
UCLASS(meta = (DisplayName = "On Interaction Used"))
class UFlowNode_OnInteractionUsed final : public UFlowNode_ComponentObserver
{
	GENERATED_UCLASS_BODY()
	
private:
	TMap<TWeakObjectPtr<AActor>, TWeakObjectPtr<UInteractionComponent>> ObservedInteractions;

protected:
	virtual void ObserveActor(TWeakObjectPtr<AActor> Actor, TWeakObjectPtr<UFlowComponent> Component) override;
	virtual void ForgetActor(TWeakObjectPtr<AActor> Actor, TWeakObjectPtr<UFlowComponent> Component) override;
	
private:
	UFUNCTION()
	void OnInteractionUsed();

protected:
	virtual void Cleanup() override;
};
