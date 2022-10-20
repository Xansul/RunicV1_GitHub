// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MassEntityTypes.h"
#include "MassEntityTemplateRegistry.h"
#include "SimpleMoveToPlayerTrait.generated.h"

/**
 * 
 */
UCLASS()
class RUNICV1_API USimpleMoveToPlayerTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

protected:

	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;
};

USTRUCT()
struct FSimpleMoveToPlayerTag : public FMassTag
{
	GENERATED_BODY()
};
