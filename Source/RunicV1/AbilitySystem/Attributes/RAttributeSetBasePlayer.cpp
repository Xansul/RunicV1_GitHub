// Fill out your copyright notice in the Description page of Project Settings.


#include "RAttributeSetBasePlayer.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "RunicV1/Characters/RCharacterAbilityBase.h"

URAttributeSetBasePlayer::URAttributeSetBasePlayer()
{

}

void URAttributeSetBasePlayer::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	//Get target character, should be owner character
	AActor* TargetActor = nullptr;
	ARCharacterAbilityBase* TargetCharacter = nullptr;

	if (Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetCharacter = Cast<ARCharacterAbilityBase>(Data.Target.AbilityActorInfo->AvatarActor.Get());
	}

	//Execute damage
	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		//******************TODO: implement shield check before executing damage

		//store temp damage variable
		const float LocalDamage = GetDamage();
		
		//reset damage attribute
		SetDamage(0.f);

		//temp variable
		bool WasAlive = true;

		if (TargetCharacter)
		{
			WasAlive = TargetCharacter->IsAlive();
		}

		if (LocalDamage > 0)
		{
			//Find new health then apply clamped version
			float LocalHealth = GetHealth();
			float NewHealth = LocalHealth - LocalDamage;
			SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));
		}

		//Apply death if health is 0
		if (!TargetCharacter->IsAlive())
		{
			TargetCharacter->Death(TargetCharacter);
			TargetCharacter->GetAbilitySystemComponent()->AddLooseGameplayTag(FGameplayTag::RequestGameplayTag(FName("State.Dead")));
		}

	}
	//Clamp other changes
	//Health clamping
	else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		//only positive changes to health should go through this
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	//Flow clamping
	else if (Data.EvaluatedData.Attribute == GetFlowAttribute())
	{
		SetFlow(FMath::Clamp(GetFlow(), 0.0f, GetMaxFlow()));
	}
}