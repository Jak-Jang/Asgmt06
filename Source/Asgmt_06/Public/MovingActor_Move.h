#pragma once

#include "CoreMinimal.h"
#include "MovingActor_Base.h"
#include "MovingActor_Move.generated.h"


UCLASS()
class ASGMT_06_API AMovingActor_Move : public AMovingActor_Base
{
	GENERATED_BODY()

public:
	AMovingActor_Move();

protected:
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|MaxRange")
	double MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|Speed|Move")
	FVector MoveSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void MovePingpong(float DeltaTime);
};
