// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class RAbilityInputID : uint8
{
	//0 None
	None				UMETA(DisplayName = "None"),
	//1 Confirm
	Confirm				UMETA(DisplayName = "Confirm"),
	//2 Cancel
	Cancel				UMETA(DisplayName = "Cancel"),
	//3 Sprint
	Sprint				UMETA(DisplayName = "Sprint"),
	//4 Jump
	Jump				UMETA(DisplayName = "Jump"),
	//5 Melee attack
	Melee				UMETA(DisplayName = "Melee"),
	//6 Cast slot 1
	Cast1				UMETA(DisplayName = "Cast1"),
	//7 Cast slot 2
	Cast2				UMETA(DisplayName = "Cast2"),
	//8 Cast slot 3
	Cast3				UMETA(DisplayName = "Cast3"),
	//9 Cast slot 4
	Cast4				UMETA(DisplayName = "Cast4"),
	//10 Shield
	Shield				UMETA(DisplayName = "Shield"),
	//11 Teleport
	Teleport			UMETA(DisplayName = "Teleport")
};
