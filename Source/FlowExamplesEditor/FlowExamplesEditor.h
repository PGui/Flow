#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyle.h"

class FFlowExamplesEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FFlowExamplesEditorModule& Get() { return FModuleManager::LoadModuleChecked<FFlowExamplesEditorModule>("FlowExamplesEditor"); }
	static inline bool IsAvailable() { return FModuleManager::Get().IsModuleLoaded("FlowExamplesEditor"); }
};
