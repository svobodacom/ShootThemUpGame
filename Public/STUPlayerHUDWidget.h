// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUPlayerHUDWidget.generated.h"


UCLASS()
class SHOOTTHEMUP_16_05_API USTUPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BluePrintCallable, Category = "UI")
	float GetHealthPercent() const;

	UFUNCTION(BluePrintCallable, Category = "UI")
	bool GetCurrentWeaponUIData(FWeaponUIData& UIData) const;

	UFUNCTION(BluePrintCallable, Category = "UI")
	bool GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool IsPlayerAlive() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool IsPlayerSpectating() const;

	// BlueprintImplementableEvent позволяет создать Event в блюпринтах на основе данной функции
	// Тело функции создавать не нужно!
	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
	void OnTakeDamage();

	virtual bool Initialize() override;

private:
	void OnHealthChanged(float Health, float HealthDelta);

};
