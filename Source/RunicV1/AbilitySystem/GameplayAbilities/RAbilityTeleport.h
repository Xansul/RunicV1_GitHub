// Tyler Call 2022

#pragma once

#include "CoreMinimal.h"
#include "RGameplayAbilityBase.h"
#include "RAbilityTeleport.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API URAbilityTeleport : public URGameplayAbilityBase
{
	GENERATED_BODY()

public:

	//constructor
	URAbilityTeleport();

	//override ActivateAbility() from parent class - calls CommitAbility() and EndAbility()
	//virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
};
