using UnrealBuildTool;

public class FlowExamplesEditorTarget : TargetRules
{
	public FlowExamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("FlowExamplesEditor");

		//DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
