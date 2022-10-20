// Fill out your copyright notice in the Description page of Project Settings.


#include "RCharacterAbilityBase.h"
#include "RunicV1/AbilitySystem/Attributes/RAttributeSetBasePlayer.h"
#include "../RAbilitySystemComponent.h"

ARCharacterAbilityBase::ARCharacterAbilityBase()
{
	//ASC setup
	AbilitySystemComponent = CreateDefaultSubobject<URAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	//Initialize shield variables
	IsBlocking = false;
	FlowReturnBase = 10.0f;
}

UAbilitySystemComponent* ARCharacterAbilityBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

//Initialize ASC
void ARCharacterAbilityBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

//Check if character is facing damage source - return effect with damage and returned flow in custom Effect
//************ TODO: transfer attribute change logic to RAttributeSetPlayerBase, allow for full effect spec to be passed in and applied

void ARCharacterAbilityBase::ShieldCheck(AActor* DamageSource, float ShieldTimer, float BaseDamage)
{
	//dynamic effect that just has damage
	UGameplayEffect* NewEffect = NewObject<UGameplayEffect>(GetTransientPackage(), FName("GE_CustomDamage"));
	NewEffect->Modifiers.SetNum(1);

	NewEffect->Modifiers[0].ModifierMagnitude = FScalableFloat(BaseDamage);
	NewEffect->Modifiers[0].ModifierOp = EGameplayModOp::Additive;
	NewEffect->Modifiers[0].Attribute = URAttributeSetBasePlayer::GetDamageAttribute();
	NewEffect->DurationPolicy = EGameplayEffectDurationType::Instant;

	//return all damage and no flow if character is not blocking, otherwise proceed with calculation
	if (IsBlocking == true)
	{
		//return all damage and no flow if ShieldTimer is at 0, otherwise proceed
		if (!ShieldTimer == 0.0f)
		{
			//get actor rotations
			FRotator DamageRotation = DamageSource->GetActorRotation();
			FRotator SelfRotation = this->GetActorRotation();

			float RotatorResult = SelfRotation.Yaw - DamageRotation.Yaw;

			if (RotatorResult > 100.0f || RotatorResult < -100.0f)
			{
				//dynamic effect that includes flow
				UGameplayEffect* NewEffectFlow = NewObject<UGameplayEffect>(GetTransientPackage(), FName("GE_CustomDamageFlow"));
				NewEffectFlow->Modifiers.SetNum(2);

				//clamp returned flow
				float ReturnedFlow = FlowReturnBase - (ShieldTimer * 2.0f);
				ReturnedFlow = FMath::Clamp(ReturnedFlow, 0.0f, FlowReturnBase);

				//adjust damage based on time shield has been held
				float NewDamage;

				//return 0 damage if shield is held for short time
				if (ShieldTimer < 5.0f)
				{
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Perfect Block!"));

					NewDamage = 0.0f;

					//update new effect
					//damage modifier
					NewEffectFlow->Modifiers[0].ModifierMagnitude = FScalableFloat(NewDamage);
					NewEffectFlow->Modifiers[0].ModifierOp = EGameplayModOp::Additive;
					NewEffectFlow->Modifiers[0].Attribute = URAttributeSetBasePlayer::GetDamageAttribute();

					//Flow modifier
					NewEffectFlow->Modifiers[1].ModifierMagnitude = FScalableFloat(ReturnedFlow);
					NewEffectFlow->Modifiers[1].ModifierOp = EGameplayModOp::Additive;
					NewEffectFlow->Modifiers[1].Attribute = URAttributeSetBasePlayer::GetFlowAttribute();
					NewEffectFlow->DurationPolicy = EGameplayEffectDurationType::Instant;

					AbilitySystemComponent->ApplyGameplayEffectToSelf(NewEffectFlow, 0.0f, AbilitySystemComponent->MakeEffectContext());

				}
				//return 1/4 damage if shield is held longer
				else
				{
					NewDamage = BaseDamage / 4.0f;

					//update new effect
					//damage modifier
					NewEffectFlow->Modifiers[0].ModifierMagnitude = FScalableFloat(NewDamage);
					NewEffectFlow->Modifiers[0].ModifierOp = EGameplayModOp::Additive;
					NewEffectFlow->Modifiers[0].Attribute = URAttributeSetBasePlayer::GetDamageAttribute();

					//Flow modifier
					NewEffectFlow->Modifiers[1].ModifierMagnitude = FScalableFloat(ReturnedFlow);
					NewEffectFlow->Modifiers[1].ModifierOp = EGameplayModOp::Additive;
					NewEffectFlow->Modifiers[1].Attribute = URAttributeSetBasePlayer::GetFlowAttribute();
					NewEffectFlow->DurationPolicy = EGameplayEffectDurationType::Instant;

					AbilitySystemComponent->ApplyGameplayEffectToSelf(NewEffectFlow, 0.0f, AbilitySystemComponent->MakeEffectContext());
				}

			}
			else
			{
				AbilitySystemComponent->ApplyGameplayEffectToSelf(NewEffect, 0.0f, AbilitySystemComponent->MakeEffectContext());
			}
		}
		else
		{
			AbilitySystemComponent->ApplyGameplayEffectToSelf(NewEffect, 0.0f, AbilitySystemComponent->MakeEffectContext());
		}
	}
	else
	{
		AbilitySystemComponent->ApplyGameplayEffectToSelf(NewEffect, 0.0f, AbilitySystemComponent->MakeEffectContext());
	}
}
