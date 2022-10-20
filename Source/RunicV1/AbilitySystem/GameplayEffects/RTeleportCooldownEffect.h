// Tyler Call 2022

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "RTeleportCooldownEffect.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API URTeleportCooldownEffect : public UGameplayEffect
{
	GENERATED_BODY()

public:
	
	//constructors
	URTeleportCooldownEffect();

	//cooldown variable
	UPROPERTY(EditAnywhere, Category = "Cooldown")
	float Cooldown;
	
};
