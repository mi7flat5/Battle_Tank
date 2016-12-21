// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"
class UTankTrack;
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLE_TANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
		
	UTankTrack* leftTrack = nullptr;
	UTankTrack* rightTrack = nullptr;

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)override;
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void intendMoveForward(float controlThrow);
		
	UFUNCTION(BlueprintCallable, Category = Input)
	void intendTurnRight(float controlThrow);
		
	UFUNCTION(BlueprintCallable, Category = Setup)
	void initialize(UTankTrack * inLeftTrack, UTankTrack * inRightTrack);

};
