using UnrealBuildTool;

public class FlowExamplesTarget : TargetRules
{
	public FlowExamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("FlowExamples");

        //DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
