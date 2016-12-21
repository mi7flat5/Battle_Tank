// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()
		
		ATank();
		virtual void BeginPlay() override;
};
