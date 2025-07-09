#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"


ASpawnVolume::ASpawnVolume() 
	: Slope(0.0f), ScaleMin(4.0f), ScaleMax(6.0f)
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	FVector BoxOrigin = SpawningBox->GetComponentLocation();

	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));
}

void ASpawnVolume::SpawnWorld(TSubclassOf<AActor> WillBeSpawned)
{
	if (!WillBeSpawned) return;

	// Random Rotation and Scale
	FRotator SpawnRotator = FRotator(
		FMath::FRandRange(-Slope, Slope),
		FMath::FRandRange(0.0f, 360.0f),
		FMath::FRandRange(-Slope, Slope));
	FVector SpawnScale = FVector(FMath::FRandRange(ScaleMin, ScaleMax));

	// Trasform(Rotator, Location, Scale)
	FTransform SpawnTransform(SpawnRotator, GetRandomPointInVolume(), SpawnScale);

	// SpawnActor with Transform
	GetWorld()->SpawnActor<AActor>(WillBeSpawned, SpawnTransform);
}