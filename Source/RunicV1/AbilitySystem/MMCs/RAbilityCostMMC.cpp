// Fill out your copyright notice in the Description page of Project Settings.


#include "RAbilityCostMMC.h"
#include "RunicV1/AbilitySystem/GameplayAbilities/RGameplayAbilityBase.h"

float URAbilityCostMMC::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const URGameplayAbilityBase* Ability = Cast<URGameplayAbilityBase>(Spec.GetContext().GetAbilityInstance_NotReplicated());

	if (!Ability)
	{
		return 0.0f;
	}

	return Ability->Cost.GetValueAtLevel(Ability->GetAbilityLevel());
}