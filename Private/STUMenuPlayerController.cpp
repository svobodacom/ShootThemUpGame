// Don Silvio Copyright
#include "STUMenuPlayerController.h"
#include "STUGameInstance.h"


void ASTUMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

	GetWorld()->GetGameInstance<USTUGameInstance>()->TestString = "CHANGE NAME IN GAME!!!";
}
