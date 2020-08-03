#include "FlowerUIManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

UFlowerUIManager::UFlowerUIManager()
	: UGameInstanceSubsystem()
{
}

void UFlowerUIManager::OpenWidget(const TSubclassOf<UUserWidget> WidgetClass)
{
	if (WidgetClass == nullptr || WidgetClass->HasAnyClassFlags(CLASS_Abstract) || OpenedWidgets.Contains(WidgetClass))
	{
		return;
	}

	UUserWidget* Widget = Cast<UUserWidget>(UWidgetBlueprintLibrary::Create(GetWorld(), *WidgetClass, GetWorld()->GetFirstPlayerController()));
	OpenedWidgets.Add(WidgetClass, Widget);
	Widget->AddToViewport();
}

void UFlowerUIManager::CloseWidget(const TSubclassOf<UUserWidget> WidgetClass)
{
	if (UUserWidget* Widget = OpenedWidgets.FindRef(WidgetClass))
	{
		Widget->RemoveFromParent();
		OpenedWidgets.Remove(WidgetClass);
	}
}

void UFlowerUIManager::ToggleWidget(const TSubclassOf<UUserWidget> WidgetClass)
{
	if (OpenedWidgets.Contains(WidgetClass))
	{
		CloseWidget(WidgetClass);
	}
	else
	{
		OpenWidget(WidgetClass);
	}
}

void UFlowerUIManager::HideWidgets()
{
	for (auto WidgetIt = OpenedWidgets.CreateIterator(); WidgetIt; ++WidgetIt)
	{
		const TPair<TSubclassOf<UUserWidget>, UUserWidget*> Widget = *WidgetIt;

		HiddenWidgets.Add(Widget.Key);
		CloseWidget(Widget.Key);
	}
}

void UFlowerUIManager::RestoreWidgets()
{
	for (const TSubclassOf<UUserWidget>& WidgetClass : HiddenWidgets)
	{
		OpenWidget(WidgetClass);
	}
	HiddenWidgets.Empty();
}
