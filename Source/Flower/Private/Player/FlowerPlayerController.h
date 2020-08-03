#pragma once

#include "GameFramework/PlayerController.h"
#include "FlowerPlayerController.generated.h"

class UInteractionComponent;

/**
 *
 */
UCLASS()
class AFlowerPlayerController final : public APlayerController
{
	GENERATED_UCLASS_BODY()

	virtual void SetupInputComponent() override;
	virtual void PlayerTick(float DeltaTime) override;

private:
	TArray<TWeakObjectPtr<UInteractionComponent>> PossibleInteractions;
	TWeakObjectPtr<UInteractionComponent> ActiveInteraction;
	
	void OnInteractionEnter(const TWeakObjectPtr<UInteractionComponent> Interaction);
	void OnInteractionExit(const TWeakObjectPtr<UInteractionComponent> Interaction);

	void ActivateInteraction(const TWeakObjectPtr<UInteractionComponent> Interaction);
	void DectivateInteraction();
	
	UFUNCTION()
	void OnInteractionUsed();
};
