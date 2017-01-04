// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	CheckController();
	ATank* PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank)
		return nullptr;

	return Cast<ATank>(PlayerTank);

}

void ATankAIController::CheckController()
{
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto CurrentTank = GetControlledTank();
	if (!CurrentTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController has no tank possessed."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s"), *CurrentTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


