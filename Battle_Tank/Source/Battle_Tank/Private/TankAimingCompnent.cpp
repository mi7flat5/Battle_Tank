// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "Projectile.h"
#include "TankAimingCompnent.h"
#include"TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingCompnent::UTankAimingCompnent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}
void UTankAimingCompnent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - lastFiredTime) < reloadTime)
	{
		fireingState = EFireingState::RELOADING;
	}
	else if (barrelIsMoving())
	{
		fireingState = EFireingState::AIMING;
	}
	else { fireingState = EFireingState::LOCKED; }
	
}
bool UTankAimingCompnent::barrelIsMoving()const
{
	
	if (ensure(barrel)) 
	{
		if (aimDir.Equals(barrel->GetForwardVector(), 0.01))
			return false;
	}
	return true;
}
// Called when the game starts
void UTankAimingCompnent::BeginPlay()
{
	//Super::BeginPlay();
	lastFiredTime = FPlatformTime::Seconds();
	// ...
	
}

void UTankAimingCompnent::aimAt(FVector aimLoc)
{
	if (ensure(barrel && ProjectileBlueprint)) 
	{
		FVector	tossVelocity;

		if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			tossVelocity,
			barrel->GetSocketLocation(FName("BarrelEnd")),
			aimLoc,
			fireingVelocity,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace)
			)
		{
			aimDir = tossVelocity.GetSafeNormal();
			moveBarrel(aimDir);
		}
	}
}

void UTankAimingCompnent::fire()
{
	
	if (fireingState == EFireingState::LOCKED)
	{
		if (ensure(barrel && ProjectileBlueprint)) 
		{
			auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
				barrel->GetSocketLocation(FName("BarrelEnd")),
				barrel->GetSocketRotation(FName("BarrelEnd")));
			projectile->launchProjectile(fireingVelocity);
			lastFiredTime = FPlatformTime::Seconds();
		}
	}
}

void UTankAimingCompnent::initialize(UTankBarrel * inBarrel, UTankTurret * inTurret)
{
	barrel = inBarrel;
	turret = inTurret;
}



void UTankAimingCompnent::moveBarrel(FVector dir) const
{	
	if (ensure(barrel&&turret)) 
	{
		auto barrelRotator = barrel->GetForwardVector().Rotation();
		auto aimRotator = dir.Rotation();
		auto deltaRotator = aimRotator - barrelRotator;

		barrel->elevate(deltaRotator.Pitch);

		if (FMath::Abs(deltaRotator.Yaw) < 180)
		{
			turret->rotate(deltaRotator.Yaw);
		}
		else
		{
			turret->rotate(-deltaRotator.Yaw);
		}
	}
}
