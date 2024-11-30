// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetBox.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitTargetDelegate);

class UStaticMeshComponent;
class URotatingMovementComponent;
class USphereComponent;
class UNiagaraSystem;

UCLASS()
class HOMEWORK2_API ATargetBox : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintAssignable, Category = "TargetBox")
	FOnHitTargetDelegate OnHitTarget;

	// Sets default values for this actor's properties
	ATargetBox();

	UFUNCTION()
	void OnBeginOverlapComponentEvent(
		UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	TObjectPtr<URotatingMovementComponent> RotatingMovementComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	TObjectPtr<USphereComponent> ColliderComponent;

	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	TObjectPtr<UNiagaraSystem> HitEffect;

	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	float EffectSpawnOffset{ 90 };

	bool SecondTimeHurt = false;
};
