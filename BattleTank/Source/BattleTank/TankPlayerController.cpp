// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CheckController();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::CheckController()
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	auto CurrentTank = GetControlledTank();
	if (!CurrentTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController has no tank possessed."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *CurrentTank->GetName());
	}
}

void ATankPlayerController::AimTowardsCrosshair()
{
	// no use going through entire method if there's no controlled tank
	if (!GetControlledTank())
		return;

	// out parameter
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}

