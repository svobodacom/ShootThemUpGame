// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "STUPlayerController.generated.h"

class USTURespawnComponent;

UCLASS()
class SHOOTTHEMUP_16_05_API ASTUPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASTUPlayerController();

protected:
	UPROPERTY(VisibleAnywhere, BluePrintReadWrite, Category = "Components")
	USTURespawnComponent* RespawnComponent;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void SetupInputComponent() override;

private:
	void OnPauseGame();


};
