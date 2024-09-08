// Don Silvio Copyright
#include "STUAIController.h"
#include "STUAICharacter.h"
#include "STUAIPerceptionComponent.h"


ASTUAIController::ASTUAIController()
{
	STUAIPereceptionComponent = CreateDefaultSubobject<USTUAIPerceptionComponent>("STUPereceptionComponent");
	SetPerceptionComponent(*STUAIPereceptionComponent);
}

void ASTUAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);

	if (STUCharacter)
	{
		RunBehaviorTree(STUCharacter->BehaviorTreeAsset);
	}
}



void ASTUAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto AimActor = STUAIPereceptionComponent->GetClosestEnemy();
	SetFocus(AimActor);
}
