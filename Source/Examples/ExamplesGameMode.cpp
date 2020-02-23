#include "ExamplesGameMode.h"
#include "ExamplesHUD.h"
#include "ExamplesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExamplesGameMode::AExamplesGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AExamplesHUD::StaticClass();
}
