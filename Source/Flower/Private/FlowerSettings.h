#pragma once

#include "Engine/DeveloperSettings.h"
#include "FlowerSettings.generated.h"

class UUserWidget;

/**
 *
 */
UCLASS(Config = Game, defaultconfig, meta = (DisplayName = "Flower"))
class UFlowerSettings final : public UDeveloperSettings
{
	GENERATED_UCLASS_BODY()

	static UFlowerSettings* Get() { return CastChecked<UFlowerSettings>(StaticClass()->GetDefaultObject()); }

	UPROPERTY(Config, EditAnywhere, Category = "Widgets")
	TSubclassOf<UUserWidget> InteractionWidget;
};
