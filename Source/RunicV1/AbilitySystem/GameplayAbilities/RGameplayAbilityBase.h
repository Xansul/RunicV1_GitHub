// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RunicV1/RunicV1.h"
#include "RAbilityProjectileBase.h"
#include "GameplayEffect.h"
#include "RAbilityProjectileBase.h"
#include "RGameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API URGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:

	//Cost associated with ability, this is overridden in subclassed abilities
	//RAbilityCostMMC pulls from this to assign costs to GameplayAbilities through GE_AbilityCost
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cost")
	FScalableFloat Cost;

	//Input ID for ability
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "InputID")
	RAbilityInputID InputID = RAbilityInputID::None;
	
};
