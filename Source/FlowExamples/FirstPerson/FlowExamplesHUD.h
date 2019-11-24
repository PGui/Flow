#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FlowExamplesHUD.generated.h"

UCLASS()
class AFlowExamplesHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFlowExamplesHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

