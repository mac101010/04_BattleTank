// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

/*
void ATankAIController::CheckController()
{
	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));

	auto CurrentTank = Cast<ATank>(GetPawn());
	if (!CurrentTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController has no tank possessed."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s"), *CurrentTank->GetName());
	}
}
*/

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();
	}
}


