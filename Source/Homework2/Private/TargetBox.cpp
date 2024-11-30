// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBox.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"

#include "NiagaraFunctionLibrary.h"

// Sets default values
ATargetBox::ATargetBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	//ColliderComponent->SetCollisionResponseToAllChannels(ECR_Overlap);

	FScriptDelegate delegate;
	delegate.BindUFunction(this, FName("OnBeginOverlapComponentEvent"));
	ColliderComponent->OnComponentBeginOverlap.AddUnique(delegate);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingComponent");
}

void ATargetBox::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("%s"), *OtherActor->GetName());
	if (OtherActor->ActorHasTag(FName("Bullet")) || OtherActor->ActorHasTag(FName("Player")) && SecondTimeHurt)
	{
		if (!SecondTimeHurt)
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *OtherActor->GetName());
			OtherActor->Destroy();

			SecondTimeHurt = true;
			FVector currentVector = GetActorScale3D();
			FVector newVector = 0.5f * currentVector;
			SetActorScale3D(newVector);

		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s"), *OtherActor->GetName());

			if (HitEffect)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(
					this, HitEffect, OtherActor->GetActorLocation()
				);
			}

			if (OnHitTarget.IsBound())
			{
				OnHitTarget.Broadcast();
			}

			OtherActor->Destroy();
			Destroy();

		}

	}

}



