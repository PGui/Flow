using UnrealBuildTool;
using System.Collections.Generic;

public class FlowExamplesTarget : TargetRules
{
	public FlowExamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("FlowExamples");
	}
}
