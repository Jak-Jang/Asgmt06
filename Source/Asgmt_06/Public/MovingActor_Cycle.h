#pragma once

#include "CoreMinimal.h"
#include "MovingActor_Base.h"
#include "MovingActor_Cycle.generated.h"


UCLASS()
class ASGMT_06_API AMovingActor_Cycle : public AMovingActor_Base
{
	GENERATED_BODY()
	
public:
	AMovingActor_Cycle();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|Speed|Move")
	FVector MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|Speed|Rotate")
	float PitchSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|Speed|Rotate")
	float YawSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|Speed|Rotate")
	float RollSpeed;

	virtual void Tick(float DeltaTime) override;
};