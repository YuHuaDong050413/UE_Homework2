// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework2GameMode.h"
#include "Homework2Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework2GameMode::AHomework2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
