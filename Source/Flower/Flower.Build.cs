using UnrealBuildTool;

public class Flower : ModuleRules
{
    public Flower(ReadOnlyTargetRules Target) : base(Target)
    {
        bUseUnity = false;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Flow"
        });

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AIModule",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "InputCore",
            "GameplayTags",
            "Slate",
            "SlateCore",
            "UMG"
        });
    }
}
