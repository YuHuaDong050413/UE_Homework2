// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Homework2/Public/TargetBox.h"

void UScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		if (!Actor) continue;
		if (ATargetBox* Target = Cast<ATargetBox>(Actor))
		{
			Target->OnHitTarget.AddDynamic(this, &UScreenWidget::OnHitTarget);
		}
	}

}

void UScreenWidget::OnHitTarget()
{
	Score++;
	if (ScoreText)
	{
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), Score)));

	}
}