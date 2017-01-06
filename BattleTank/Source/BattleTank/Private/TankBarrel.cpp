// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), Time, RelativeSpeed);

	auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	UE_LOG(LogTemp, Warning, TEXT("Elevation: %f"), RawNewElevation)
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}


