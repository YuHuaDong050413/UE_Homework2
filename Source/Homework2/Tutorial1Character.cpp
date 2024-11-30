// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial1Character.h"


// Sets default values
ATutorial1Character::ATutorial1Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATutorial1Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATutorial1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATutorial1Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATutorial1Character::SpawnActor()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(actorBPToSpawn, GetActorTransform());
}

