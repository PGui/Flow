using UnrealBuildTool;
using System.Collections.Generic;

public class ExamplesTarget : TargetRules
{
	public ExamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		//DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Examples");
	}
}
