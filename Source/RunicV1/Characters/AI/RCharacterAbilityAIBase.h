// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../RCharacterAbilityBase.h"
#include "RunicV1/AbilitySystem/Attributes/RAttributeSetBasePlayer.h"
#include "RCharacterAbilityAIBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API ARCharacterAbilityAIBase : public ARCharacterAbilityBase
{
	GENERATED_BODY()
	
public:

	ARCharacterAbilityAIBase();

	//override IsAlive() function
	virtual bool IsAlive() override;

protected:

	//Attribute set variable
	UPROPERTY(BlueprintReadOnly, Category = Attributes)
	class URAttributeSetBasePlayer* AttributeSetBase;
};
