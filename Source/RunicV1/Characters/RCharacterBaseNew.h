// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RCharacterBaseNew.generated.h"

UCLASS()
class RUNICV1_API ARCharacterBaseNew : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARCharacterBaseNew();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Check if character is alive - meant to be overriden
	virtual bool IsAlive();

	//Death function - meant to be overriden (add loose gameplay tag upon death)
	virtual void Death(ARCharacterBaseNew* Character);

};
