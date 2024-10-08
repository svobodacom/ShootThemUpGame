// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "STUBaseCharacter.h"
#include "STUAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class SHOOTTHEMUP_16_05_API ASTUAICharacter : public ASTUBaseCharacter
{
	GENERATED_BODY()

public:
	ASTUAICharacter(const FObjectInitializer& ObjInit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;
	
protected:
	virtual void OnDeath() override;


};
