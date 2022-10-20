// Fill out your copyright notice in the Description page of Project Settings.


#include "RCharacterAbilityAIBase.h"

ARCharacterAbilityAIBase::ARCharacterAbilityAIBase()
{
	//Add base player attribute set
	AttributeSetBase = CreateDefaultSubobject<URAttributeSetBasePlayer>(TEXT("AttributeSetBase"));
}

//return if character is alive or not
bool ARCharacterAbilityAIBase::IsAlive()
{
	return AttributeSetBase->GetHealth() > 0.f;
}