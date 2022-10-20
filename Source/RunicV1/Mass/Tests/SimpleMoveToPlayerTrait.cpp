// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMoveToPlayerTrait.h"

void USimpleMoveToPlayerTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	BuildContext.AddTag<FSimpleMoveToPlayerTag>();
}