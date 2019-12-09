using UnrealBuildTool;

public class FlowExamples : ModuleRules
{
	public FlowExamples(ReadOnlyTargetRules Target) : base(Target)
	{
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
