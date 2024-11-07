// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUGameInstance.generated.h"


UCLASS()
class SHOOTTHEMUP_16_05_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FName GetStartupLevelName() const { return StartupLevelName; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName StartupLevelName = NAME_None;
};
