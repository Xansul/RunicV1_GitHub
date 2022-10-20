// Tyler Call 2022


#include "RunicV1/AbilitySystem/GameplayEffects/RTeleportCooldownEffect.h"
#include "RAbilityTeleport.h"

URAbilityTeleport::URAbilityTeleport()
{
	//set default variables
	//no cost
	Cost = 0.0f;

	//instancing
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerExecution;

	//cooldown effect
	CooldownGameplayEffectClass = URTeleportCooldownEffect::StaticClass();

	//input
	InputID = RAbilityInputID::Teleport;

	//associated tags
	ActivationOwnedTags = FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("State.Busy")));
	ActivationBlockedTags = FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("State.Busy")));
}