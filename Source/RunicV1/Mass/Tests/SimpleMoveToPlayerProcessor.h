// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "SimpleMoveToPlayerTrait.h"
#include "MassCommonFragments.h"
#include "SimpleMoveToPlayerProcessor.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API USimpleMoveToPlayerProcessor : public UMassProcessor
{
	GENERATED_BODY()

public:

	USimpleMoveToPlayerProcessor();
	
protected:

	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;

private:

	FMassEntityQuery EntityQuery;

};
