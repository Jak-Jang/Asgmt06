#include "MovingActor_Flash.h"


AMovingActor_Flash::AMovingActor_Flash() : bIsHide(true), FlashDelay(5.0f)
{
}

void AMovingActor_Flash::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer
	(
		FlashTimerHandle,
		this,
		&AMovingActor_Flash::Hide,
		FlashDelay,
		true
	);
}

void AMovingActor_Flash::Hide()
{
	SetActorHiddenInGame(bIsHide);

	if (bIsHide) SetActorEnableCollision(false);
	else SetActorEnableCollision(true);

	if (bIsHide) bIsHide = false;
	else bIsHide = true;
}