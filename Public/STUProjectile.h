// Don Silvio Copyright
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class USTUWeaponFXComponent;

UCLASS()
class SHOOTTHEMUP_16_05_API ASTUProjectile : public AActor
{
	GENERATED_BODY()

public:	
	ASTUProjectile();

	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction;  }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	USTUWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageRadius = 180.0f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageAmount = 80.0f;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool DoFullDamage = false;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float LifeSeconds = 5.0f;

	virtual void BeginPlay() override;

private:
	FVector ShotDirection;

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		                  FVector NormalImpulse, const FHitResult& Hit);


	AController* GetController() const;

};
 