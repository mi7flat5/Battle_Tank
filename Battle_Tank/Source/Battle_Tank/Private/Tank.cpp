// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "Tank.h"
#include "TankAimingCompnent.h"
#include"TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	tankAimingComponent = CreateDefaultSubobject<UTankAimingCompnent>(FName("Aiming Component"));

}



// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
//{
//	Super::SetupPlayerInputComponent(InputComponent);
//
//}
void ATank::aimAt(FVector hitLoc) const
{
	tankAimingComponent->aimAt(hitLoc,fireingVelocity);
	
}

void ATank::setBarrellReference(UTankBarrel* inBarrel)
{
	verifyf(inBarrel, TEXT("nullpter reference for Barrel"));
	tankAimingComponent->setBarrel(inBarrel);
	barrel = inBarrel;
}

void ATank::setTurretReference(UTankTurret* inTurret)
{
	verifyf(inTurret, TEXT("nullpter reference for turret"));
	tankAimingComponent->setTurret(inTurret);
}
void ATank::fireTank() 
{
	bool bIsReloaded = (FPlatformTime::Seconds() - lastFiredTime) > reloadTime;
	if (barrel && bIsReloaded) 
	{
		auto projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
		barrel->GetSocketLocation(FName("BarrelEnd")),
		barrel->GetSocketRotation(FName("BarrelEnd")));
		projectile->launchProjectile(fireingVelocity);
		bIsReloaded = false;
		lastFiredTime = FPlatformTime::Seconds();
	}
}