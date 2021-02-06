using UnrealBuildTool;

public class FlowerEditorTarget : TargetRules
{
	public FlowerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange(new[]
		{ 
			"Flower"
		});
    }
}
