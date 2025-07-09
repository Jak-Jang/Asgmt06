#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class ASGMT_06_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|SpawnDetail")
	float Slope;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|SpawnDetail")
	float ScaleMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning|SpawnDetail")
	float ScaleMax;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	FVector GetRandomPointInVolume() const;
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnWorld(TSubclassOf<AActor> WillBeSpawned);
};
