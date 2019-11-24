#include "FlowExamplesGameMode.h"
#include "FlowExamplesHUD.h"
#include "FlowExamplesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFlowExamplesGameMode::AFlowExamplesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFlowExamplesHUD::StaticClass();
}
