// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::intendMoveForward(float controlThrow)
{
	

	//TODO fix double speed if stick and triggers used together
	leftTrack->setThrottle(controlThrow);
	rightTrack->setThrottle(controlThrow);
}

void UTankMovementComponent::intendTurnRight(float controlThrow)
{
	leftTrack->setThrottle(controlThrow);
	rightTrack->setThrottle(-controlThrow);
}

void UTankMovementComponent::initialize(UTankTrack* inLeftTrack, UTankTrack* inRightTrack)
{
	if (inLeftTrack && inRightTrack)
	{
		leftTrack = inLeftTrack;
		rightTrack = inRightTrack;
	}
}