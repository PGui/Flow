using UnrealBuildTool;

public class FlowerTarget : TargetRules
{
	public FlowerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange(new[]
		{ 
			"Flower"
		});

        DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
