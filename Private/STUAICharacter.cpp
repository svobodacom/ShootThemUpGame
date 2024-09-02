// Don Silvio Copyright
#include "STUAICharacter.h"
#include "STUAIController.h"


ASTUAICharacter::ASTUAICharacter(const FObjectInitializer& ObjInit): Super(ObjInit)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ASTUAIController::StaticClass();
}
