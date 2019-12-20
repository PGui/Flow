using UnrealBuildTool;

public class FlowExamples : ModuleRules
{
	public FlowExamples(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "Flow",
                "HeadMountedDisplay",
                "InputCore"
            }
        );
	}
}
