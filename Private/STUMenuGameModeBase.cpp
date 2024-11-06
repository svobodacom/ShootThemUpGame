// Don Silvio Copyright
#include "STUMenuGameModeBase.h"
#include "STUMenuPlayerController.h"
#include "STUMenuHUD.h"


ASTUMenuGameModeBase::ASTUMenuGameModeBase()
{
	PlayerControllerClass = ASTUMenuPlayerController::StaticClass();
	HUDClass = ASTUMenuHUD::StaticClass();
}
