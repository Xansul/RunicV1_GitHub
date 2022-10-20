// Copyright Epic Games, Inc. All Rights Reserved.

#include "RunicV1GameMode.h"
#include "RunicV1Character.h"
#include "UObject/ConstructorHelpers.h"

ARunicV1GameMode::ARunicV1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
