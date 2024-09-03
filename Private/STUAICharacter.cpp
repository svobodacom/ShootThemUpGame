// Don Silvio Copyright
#include "STUAICharacter.h"
#include "STUAIController.h"
#include "GameFramework/CharacterMovementComponent.h"


ASTUAICharacter::ASTUAICharacter(const FObjectInitializer& ObjInit): Super(ObjInit)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ASTUAIController::StaticClass();

	bUseControllerRotationYaw = false;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
	}
}
