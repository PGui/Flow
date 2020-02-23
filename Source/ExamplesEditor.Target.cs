using UnrealBuildTool;

public class ExamplesEditorTarget : TargetRules
{
	public ExamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Examples");

        //DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
