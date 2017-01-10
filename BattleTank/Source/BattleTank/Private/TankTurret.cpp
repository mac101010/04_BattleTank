// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto Speed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = Speed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	UE_LOG(LogTemp, Warning, TEXT("Rotation: %f"), Rotation)

	SetRelativeRotation(FRotator(0, Rotation, 0));
}

