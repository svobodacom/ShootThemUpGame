// Don Silvio Copyright
#include "STUSpectatorWidget.h"
#include "STUUtils.h"
#include "STURespawnComponent.h"


bool USTUSpectatorWidget::GetRespawnTime(int32& CountDownTime) const
{
   const auto RespawnComponent = STUUtils::GetSTUPlayerComponent<USTURespawnComponent>(GetOwningPlayer());
   if (!RespawnComponent || !RespawnComponent->IsRespawnInProgress()) return false;

   CountDownTime = RespawnComponent->GetRespawnCountDown();
   return true;
}
