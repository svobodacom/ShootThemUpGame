// Don Silvio Copyright
#include "STUPlayerController.h"
#include "STURespawnComponent.h"


ASTUPlayerController::ASTUPlayerController()
{
	RespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}
