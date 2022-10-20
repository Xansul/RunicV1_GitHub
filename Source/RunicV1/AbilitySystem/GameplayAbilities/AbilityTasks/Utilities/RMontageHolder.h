// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RMontageHolder.generated.h"

UCLASS(Blueprintable)
class RUNICV1_API ARMontageHolder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARMontageHolder();

	//Holds montage reference for use in AbilityTasks
	UPROPERTY(EditAnywhere)
	UAnimMontage* Montage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
