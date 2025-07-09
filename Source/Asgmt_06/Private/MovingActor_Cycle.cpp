#include "MovingActor_Cycle.h"


AMovingActor_Cycle::AMovingActor_Cycle() 
	: MoveSpeed(0.0), PitchSpeed(0.0f), YawSpeed(0.0f), RollSpeed(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor_Cycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(PitchSpeed * DeltaTime, YawSpeed * DeltaTime, RollSpeed * DeltaTime));
	AddActorLocalOffset(MoveSpeed * DeltaTime);
}