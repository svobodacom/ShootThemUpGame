// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "STUAIController.generated.h"

class USTUAIPerceptionComponent;

UCLASS()
class SHOOTTHEMUP_16_05_API ASTUAIController : public AAIController
{
	GENERATED_BODY()

public:
	ASTUAIController();
	
protected:
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Components")
	USTUAIPerceptionComponent* STUAIPereceptionComponent;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
};