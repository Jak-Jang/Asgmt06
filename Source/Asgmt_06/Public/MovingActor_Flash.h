#pragma once

#include "CoreMinimal.h"
#include "MovingActor_Base.h"
#include "MovingActor_Flash.generated.h"


UCLASS()
class ASGMT_06_API AMovingActor_Flash : public AMovingActor_Base
{
	GENERATED_BODY()

public:
	AMovingActor_Flash();

protected:
	bool bIsHide;
	FTimerHandle FlashTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings|FlashDelay")
	float FlashDelay;

	FVector StartLotation;

	void BeginPlay() override;

	void Hide();
};
