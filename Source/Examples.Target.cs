using UnrealBuildTool;

public class ExamplesTarget : TargetRules
{
	public ExamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("Examples");

        //DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
