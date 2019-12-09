#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGame, Log, All);

class FFlowExamplesModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static inline FFlowExamplesModule& Get() { return FModuleManager::LoadModuleChecked<FFlowExamplesModule>("FlowExamples"); }
	static inline bool IsAvailable() { return FModuleManager::Get().IsModuleLoaded("FlowExamples"); }
};
