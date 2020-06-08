using UnrealBuildTool;

public class FlowerEditorTarget : TargetRules
{
	public FlowerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Flower");

        //DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
