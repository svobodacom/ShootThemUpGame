// Don Silvio Copyright
#include "STUHealthPickup.h"
#include "STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ASTUHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
   const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
   if (!HealthComponent) return false;

   return HealthComponent->TryToAddHealth(HealthAmount);
}
