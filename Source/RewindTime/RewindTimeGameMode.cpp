// Copyright Epic Games, Inc. All Rights Reserved.

#include "RewindTimeGameMode.h"
#include "RewindTimeHUD.h"
#include "RewindTimeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARewindTimeGameMode::ARewindTimeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ARewindTimeHUD::StaticClass();
}
