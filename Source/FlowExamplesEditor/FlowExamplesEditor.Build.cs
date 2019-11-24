using UnrealBuildTool;

public class FlowExamplesEditor : ModuleRules
{
    public FlowExamplesEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "Flow",
                "InputCore",
                "UnrealEd"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
                "UMG"
            }
        );

        PrivateIncludePathModuleNames.AddRange(
            new string[]
            {
                "MainFrame"
            }
        );
    }
}
