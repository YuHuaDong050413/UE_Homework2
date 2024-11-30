// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Homework2/Public/TargetBox.h"
#include "ScreenWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class HOMEWORK2_API UScreenWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "TargetBox", meta = (BindWidget))
	TObjectPtr<UTextBlock> ScoreText;

	UPROPERTY(EditDefaultsOnly, Category = "TargetBox")
	TSubclassOf<ATargetBox> TargetClass;

	int Score;

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnHitTarget();
	
};
