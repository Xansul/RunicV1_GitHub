// Tyler Call 2022


#include "RTeleportCooldownEffect.h"

URTeleportCooldownEffect::URTeleportCooldownEffect()
{
	//set defaults
	DurationPolicy = EGameplayEffectDurationType::HasDuration;
	Cooldown = 1.0f;

	//create and assign modifier magnitude
	DurationMagnitude = FGameplayEffectModifierMagnitude(Cooldown);

	//create and add tag container
	FInheritedTagContainer Tags = FInheritedTagContainer();
	Tags.Added = FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("State.Teleport.TeleportCooldown")));
	InheritableOwnedTagsContainer = Tags;
}