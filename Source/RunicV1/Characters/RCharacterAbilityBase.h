// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RCharacterBaseNew.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "RCharacterAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API ARCharacterAbilityBase : public ARCharacterBaseNew, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	//constructor
	ARCharacterAbilityBase();

	// Implement IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// Override PossesedBy function to initialize ASC
	virtual void PossessedBy(AController* NewController) override;

	//Change bool to true when GameplayAbilities activate casting circle anims
	UPROPERTY(BlueprintReadWrite)
	bool IsCastingCircle;

	//Change bool to true when GameplayAbilities activate casting rune anims
	UPROPERTY(BlueprintReadWrite)
	bool IsCastingRune;

	//Transform variable that shows where to spawn runic effects (NO LONGER IN USE)
	UPROPERTY(BlueprintReadWrite)
	FTransform RunicTransform;

	//Component that shows where to attach runic effects
	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* RunicAttachment;

	//Bool that reflects if character is blocking
	UPROPERTY(BlueprintReadWrite, Category = "Shield")
	bool IsBlocking;

	//Variable for base flow return on successful shield cast
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Shield")
	float FlowReturnBase;

	//Shield angle check - determines if shield will block damage
	UFUNCTION(BlueprintCallable, Category = "Shield")
	void ShieldCheck(AActor* DamageSource, float ShieldTimer, float BaseDamage);

	//Particle system used for teleport effect
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Teleport")
	UParticleSystem* TeleportEffect;

	virtual void Death(ARCharacterBaseNew* Character) override;

protected:

	UPROPERTY(BlueprintReadOnly)
	class URAbilitySystemComponent* AbilitySystemComponent;
};
