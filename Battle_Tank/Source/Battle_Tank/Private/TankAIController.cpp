// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAIController.h"
#include"TankAimingCompnent.h"


void ATankAIController::aimAtPlayer()
{
		FVector playerLoc = playerTank->GetActorLocation();
		aim->aimAt(playerLoc);
}
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = GetPawn();
	aim = controlledTank->FindComponentByClass<UTankAimingCompnent>();
	playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
		
	if (ensure(controlledTank && playerTank&& aim))
	{
		
		aimAtPlayer();
		if (aim->GetFiringState() == EFireingState::LOCKED)
		{
			aim->fire();
		}
		MoveToActor(playerTank, acceptanceRadius);
	}
}