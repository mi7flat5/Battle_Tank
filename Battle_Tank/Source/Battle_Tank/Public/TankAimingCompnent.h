// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingCompnent.generated.h"
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankAimingCompnent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingCompnent();

	// Called when the game starts
	virtual void BeginPlay() override;
	void setBarrel(UTankBarrel*);
	void aimAt(FVector, float)const;
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	
private:
	UTankBarrel* barrel;
		
	
	void moveBarrel(FVector dir)const;
};