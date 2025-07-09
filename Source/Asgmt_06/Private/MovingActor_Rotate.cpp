#include "MovingActor_Rotate.h"


AMovingActor_Rotate::AMovingActor_Rotate()
	: PitchSpeed(0.0f), YawSpeed(0.0f), RollSpeed(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor_Rotate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(PitchSpeed * DeltaTime, YawSpeed * DeltaTime, RollSpeed * DeltaTime));
}