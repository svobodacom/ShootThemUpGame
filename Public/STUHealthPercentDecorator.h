// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "STUHealthPercentDecorator.generated.h"


UCLASS()
class SHOOTTHEMUP_16_05_API USTUHealthPercentDecorator : public UBTDecorator
{
	GENERATED_BODY()

public:
	USTUHealthPercentDecorator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float HealthPercent = 0.7f;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
