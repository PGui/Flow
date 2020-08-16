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
            "Engine",
            "InputCore",
            "GameplayTags",
            "Slate",
            "SlateCore",
            "UMG"
        });
    }
}
