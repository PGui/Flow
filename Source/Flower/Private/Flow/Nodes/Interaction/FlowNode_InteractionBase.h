#pragma once

#include "GameplayTagContainer.h"

#include "Nodes/FlowNode.h"
#include "FlowNode_InteractionBase.generated.h"

/**
 * Base for Interaction nodes
 */
UCLASS(Abstract)
class UFlowNode_InteractionBase : public UFlowNode
{
	GENERATED_UCLASS_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Interaction")
	FGameplayTag IdentityTag;

#if WITH_EDITOR
public:
	virtual FString GetNodeDescription() const override;
#endif
};
