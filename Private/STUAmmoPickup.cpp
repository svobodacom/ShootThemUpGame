// Don Silvio Copyright
#include "STUAmmoPickup.h"
#include "STUWeaponComponent.h"
#include "STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);


bool ASTUAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
   const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
   if (!HealthComponent || HealthComponent->IsDead()) return false;

   const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
   if (!WeaponComponent) return false;

   return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
