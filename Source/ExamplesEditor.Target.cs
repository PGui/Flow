using UnrealBuildTool;
using System.Collections.Generic;

public class ExamplesEditorTarget : TargetRules
{
	public ExamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		//DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("Examples");
	}
}
