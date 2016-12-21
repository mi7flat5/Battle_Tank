// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAIController.h"
#include"TankAimingCompnent.h"
#include "Tank.h"

void ATankAIController::aimAtPlayer()
{
		FVector playerLoc = playerTank->GetActorLocation();
		aim->aimAt(playerLoc);
}
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = Cast<ATank>(GetPawn());
	aim = controlledTank->FindComponentByClass<UTankAimingCompnent>();
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (aim)
		
	if (controlledTank && playerTank)
	{
		
		aimAtPlayer();
		aim->fire();
		MoveToActor(playerTank, acceptanceRadius);
	}
}