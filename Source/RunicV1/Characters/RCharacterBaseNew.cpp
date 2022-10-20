// Fill out your copyright notice in the Description page of Project Settings.


#include "RCharacterBaseNew.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ARCharacterBaseNew::ARCharacterBaseNew()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARCharacterBaseNew::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARCharacterBaseNew::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARCharacterBaseNew::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool ARCharacterBaseNew::IsAlive()
{
	return true;
}

//Simulate physics on character death
void ARCharacterBaseNew::Death(ARCharacterBaseNew* Character)
{
	//get all skeletal mesh components
	TArray<USkeletalMeshComponent*> SkeletalMeshComps;
	Character->GetComponents<USkeletalMeshComponent>(SkeletalMeshComps);

	if (!SkeletalMeshComps.IsEmpty())
	{
		for (auto SkeletalMeshes : SkeletalMeshComps)
		{
			SkeletalMeshes->SetSimulatePhysics(true);
		}
	}
}