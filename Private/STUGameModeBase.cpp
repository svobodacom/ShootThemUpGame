// Don Silvio Copyright

#include "STUGameModeBase.h"
#include "STUBaseCharacter.h"
#include "STUPlayerController.h"
#include "STUGameHUD.h"
#include "AIController.h"


ASTUGameModeBase::ASTUGameModeBase()
{
	DefaultPawnClass = ASTUBaseCharacter::StaticClass();
	PlayerControllerClass = ASTUPlayerController::StaticClass();
	HUDClass = ASTUGameHUD::StaticClass();
}



void ASTUGameModeBase::StartPlay()
{
	Super::StartPlay();
	SpawnBots();
}



UClass* ASTUGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (InController && InController->IsA<AAIController>())
	{
		return AIPawnClass;
	}
	 
	return Super::GetDefaultPawnClassForController_Implementation(InController);
}



void ASTUGameModeBase::SpawnBots()
{
	if (!GetWorld()) return;

	for (int32 i = 0; i < GameData.PlayersNum - 1; ++i)
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		const auto STUAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);
		RestartPlayer(STUAIController);
	}
}
