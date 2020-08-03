#include "FlowNode_InteractionBase.h"

UFlowNode_InteractionBase::UFlowNode_InteractionBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = TEXT("Interaction");
#endif
}

#if WITH_EDITOR
FString UFlowNode_InteractionBase::GetNodeDescription() const
{
	return IdentityTag.IsValid() ? IdentityTag.ToString() : TEXT("Missing Identity Tag!");
}
#endif
