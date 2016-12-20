// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::intendMoveForward(float controlThrow)
{
	if (leftTrack && rightTrack)
	{
		//TODO fix double speed if stick and triggers used together
		leftTrack->setThrottle(controlThrow);
		rightTrack->setThrottle(controlThrow);
	}
}

void UTankMovementComponent::intendTurnRight(float controlThrow)
{
	if (leftTrack && rightTrack)
	{
		leftTrack->setThrottle(controlThrow);
		rightTrack->setThrottle(-controlThrow);
		auto tankName = GetOwner()->GetName();
		
	}
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto tankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	intendMoveForward(FVector::DotProduct(tankForward,AIForwardIntention ));

	intendTurnRight(FVector::CrossProduct(tankForward,AIForwardIntention ).Z);
	
}

void UTankMovementComponent::initialize(UTankTrack* inLeftTrack, UTankTrack* inRightTrack)
{
		leftTrack = inLeftTrack;
		rightTrack = inRightTrack;
}