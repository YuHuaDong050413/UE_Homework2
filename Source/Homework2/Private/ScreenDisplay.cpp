// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenDisplay.h"

void AScreenDisplay::BeginPlay()
{
	Super::BeginPlay();

	if (ScreenWidgeClass)
	{
		ScreenWidge = CreateWidget<UScreenWidget>(GetWorld(), ScreenWidgeClass);
		if (ScreenWidge)
		{
			ScreenWidge->AddToViewport();
		}
	}
}


