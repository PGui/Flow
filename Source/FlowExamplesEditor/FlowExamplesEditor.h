#pragma once

#include "ModuleInterface.h"
#include "ModuleManager.h"
#include "SlateStyle.h"

class FFlowExamplesEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FFlowExamplesEditorModule& Get() { return FModuleManager::LoadModuleChecked<FFlowExamplesEditorModule>("FlowExamplesEditor"); }
	static inline bool IsAvailable() { return FModuleManager::Get().IsModuleLoaded("FlowExamplesEditor"); }
};
