// Don Silvio Copyright
#include "STUAIController.h"
#include "STUAICharacter.h"
#include "STUAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


ASTUAIController::ASTUAIController()
{
	STUAIPereceptionComponent = CreateDefaultSubobject<USTUAIPerceptionComponent>("STUPereceptionComponent");
	SetPerceptionComponent(*STUAIPereceptionComponent);

	bWantsPlayerState = true;
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

	const auto AimActor = GetFocusOnActor();
	SetFocus(AimActor);
}



AActor* ASTUAIController::GetFocusOnActor() const
{
	if (!GetBlackboardComponent()) return nullptr;

	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
