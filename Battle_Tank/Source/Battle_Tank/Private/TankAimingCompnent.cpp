// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "TankAimingCompnent.h"
#include"TankBarrel.h"

// Sets default values for this component's properties
UTankAimingCompnent::UTankAimingCompnent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingCompnent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingCompnent::setBarrel(UTankBarrel* inBarrel)
{
	barrel = inBarrel;
}


// Called every frame
void UTankAimingCompnent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingCompnent::aimAt(FVector aimLoc,float fireingVelocity) const
{
	if (!barrel) { return; }
	FString FtoS = FString::SanitizeFloat(fireingVelocity);
	

	const FCollisionResponseParams blahb;
	const TArray<AActor*> blah;

	FVector	tossVelocity;
	if (UGameplayStatics::SuggestProjectileVelocity(
			this,
			tossVelocity,
			barrel->GetSocketLocation(FName("BarrelEnd")),
			aimLoc,
			fireingVelocity,
			ESuggestProjVelocityTraceOption::DoNotTrace
			)
		)
	{
		FVector aimDir = tossVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aiming direction is: %s"), *aimDir.ToString())
			
		moveBarrel(aimDir);
	}
}
void UTankAimingCompnent::moveBarrel(FVector dir) const
{
	auto barrelRotator = barrel->GetForwardVector().Rotation();
	auto aimRotator = dir.Rotation();
	auto deltaRotator = aimRotator - barrelRotator;
	

	barrel->elevate(5);
	
}