// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "STUBaseWidget.h"
#include "STUCoreTypes.h"
#include "STUGameOverWidget.generated.h"

class UVerticalBox;
class UButton;

UCLASS()
class SHOOTTHEMUP_16_05_API USTUGameOverWidget : public  USTUBaseWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* PlayerStatBox;

	UPROPERTY(meta = (BindWidget))
	UButton* ResetLevelButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TSubclassOf<UUserWidget> PlayerStatRowWidgetClass;

	virtual void NativeOnInitialized() override;

private:
	void OnMatchStateChanged(ESTUMatchState State);
	void UpdatePlayersStat();

	UFUNCTION()
	void OnResetLevel();
};
