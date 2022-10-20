// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "RAbilityCostMMC.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API URAbilityCostMMC : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const;
};
