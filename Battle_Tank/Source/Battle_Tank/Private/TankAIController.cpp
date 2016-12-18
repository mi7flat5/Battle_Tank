// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::aimAtPlayer()
{
		FVector playerLoc = playerTank->GetActorLocation();
		controlledTank->aimAt(playerLoc);
}
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = Cast<ATank>(GetPawn());
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (controlledTank && playerTank)
	{
		aimAtPlayer();
		controlledTank->fireTank();
	}
}