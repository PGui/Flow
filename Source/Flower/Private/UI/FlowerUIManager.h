#pragma once

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "FlowerUIManager.generated.h"

class UUserWidget;

/**
 *
 */
UCLASS()
class UFlowerUIManager final : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFlowerUIManager();
	
private:
	UPROPERTY()
	TMap<TSubclassOf<UUserWidget>, UUserWidget*> OpenedWidgets;

	UPROPERTY()
	TArray<TSubclassOf<UUserWidget>> HiddenWidgets;

public:
	void OpenWidget(const TSubclassOf<UUserWidget> WidgetClass);
	void CloseWidget(const TSubclassOf<UUserWidget> WidgetClass);
	void ToggleWidget(const TSubclassOf<UUserWidget> WidgetClass);

	void HideWidgets();
	void RestoreWidgets();
};
