// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Tutorial1Character.generated.h"

UCLASS()
class HOMEWORK2_API ATutorial1Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATutorial1Character();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void SpawnActor();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actorBPToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
