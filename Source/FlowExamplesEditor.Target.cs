using UnrealBuildTool;
using System.Collections.Generic;

public class FlowExamplesEditorTarget : TargetRules
{
	public FlowExamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("FlowExamples");
	}
}
