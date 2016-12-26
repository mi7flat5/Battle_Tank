// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tank.h"
#include "Projectile.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(
			FName("Projectile Movement Component"));
	if(ensure(projectileMovement))
	projectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void AProjectile::launchProjectile(float speed)
{
	if (ensure(projectileMovement)) 
	{
		projectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector*speed);
		projectileMovement->Activate(true);
	}
}
