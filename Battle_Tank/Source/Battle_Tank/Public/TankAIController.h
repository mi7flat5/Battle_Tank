// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

		virtual void BeginPlay()override;
		virtual void Tick(float DeltaTime)override;
		ATank* GetControlledTank() const;
	
		ATank* getPlayerTank()const;
		void aimAtPlayer();
};
