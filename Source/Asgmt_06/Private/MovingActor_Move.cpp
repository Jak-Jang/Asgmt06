#include "MovingActor_Move.h"


AMovingActor_Move::AMovingActor_Move() : StartLocation(0.0), MaxRange(0.0),	MoveSpeed(0.0)
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMovingActor_Move::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingActor_Move::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePingpong(DeltaTime);
}

void AMovingActor_Move::MovePingpong(float DeltaTime)
{
	AddActorWorldOffset(MoveSpeed * DeltaTime);

	FVector CurrentLocation = GetActorLocation();

	if ((StartLocation - CurrentLocation).SizeSquared() >= MaxRange * MaxRange)
	{
		MoveSpeed *= -1;
		StartLocation = CurrentLocation;
	}
}