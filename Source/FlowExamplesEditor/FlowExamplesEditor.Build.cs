using UnrealBuildTool;

public class FlowExamplesEditor : ModuleRules
{
    public FlowExamplesEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
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
