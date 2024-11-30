// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Homework2/Public/ScreenWidget.h"
#include "ScreenDisplay.generated.h"

/**
 * 
 */
UCLASS()
class HOMEWORK2_API AScreenDisplay : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "TargetBox")
	TSubclassOf<UScreenWidget> ScreenWidgeClass;
	
	UPROPERTY()
	TObjectPtr<UScreenWidget> ScreenWidge;
	
public:
	virtual void BeginPlay() override;
};
