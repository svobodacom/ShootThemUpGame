// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUWeaponFXComponent.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;
class UPhysicalMaterial;

// Forward declare UNiagaraFunctionLibrary method and all relevant elements as necessary
enum class ENCPoolMethod : uint8 // Yes this is necessary to forward declare with values unfortunately... Syntax dictates that this must match original definition (NiagaraCommon.h)
{
	None, AutoRelease, ManualRelease, ManualRelease_OnComplete, FreeInPool,
};

class UNiagaraFunctionLibrary 
{
public:
	static UNiagaraComponent* SpawnSystemAtLocation(const UObject* WorldContextObject, class UNiagaraSystem* SystemTemplate, 
		FVector Location, FRotator Rotation = FRotator::ZeroRotator, FVector Scale = FVector(1.f), 
		bool bAutoDestroy = true, bool bAutoActivate = true, ENCPoolMethod PoolingMethod = ENCPoolMethod::None, 
		bool bPreCullCheck = true);
};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_16_05_API USTUWeaponFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USTUWeaponFXComponent();

	void PlayImpactFX(const FHitResult& Hit);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* DefaultEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	TMap<UPhysicalMaterial*, UNiagaraSystem*> EffectsMap;
		
};
