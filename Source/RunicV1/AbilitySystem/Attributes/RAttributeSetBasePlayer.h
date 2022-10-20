// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RAttributeSetBasePlayer.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class RUNICV1_API URAttributeSetBasePlayer : public UAttributeSet
{
	GENERATED_BODY()

public:

	URAttributeSetBasePlayer();

	//Current health, limited by MaxHealth (which can be modified)
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, Health)

	//Max health
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, MaxHealth)

	//Health regen amount, is added to current health every second
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, HealthRegen)

	//Current flow (mana), limited by MaxFlow (which can be modified)
	UPROPERTY(BlueprintReadOnly, Category = "Flow")
	FGameplayAttributeData Flow;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, Flow)

	//Max flow
	UPROPERTY(BlueprintReadOnly, Category = "Flow")
	FGameplayAttributeData MaxFlow;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, MaxFlow)

	//Flow regen amount, is added to current flow every second
	UPROPERTY(BlueprintReadOnly, Category = "Flow")
	FGameplayAttributeData FlowRegen;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, FlowRegen)

	//Temp variable for received damage
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(URAttributeSetBasePlayer, Damage)

	//Inherited functions
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
};
