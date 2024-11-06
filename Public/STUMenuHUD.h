// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STUMenuHUD.generated.h"


UCLASS()
class SHOOTTHEMUP_16_05_API ASTUMenuHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category ="UI")
	TSubclassOf<UUserWidget> MenuWidgetClass;

	virtual void BeginPlay() override;

};
