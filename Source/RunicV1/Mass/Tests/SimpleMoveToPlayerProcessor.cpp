// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMoveToPlayerProcessor.h"

USimpleMoveToPlayerProcessor::USimpleMoveToPlayerProcessor()
{
	bAutoRegisterWithProcessingPhases = true;
	ExecutionFlags = (int32)EProcessorExecutionFlags::All;
	ExecutionOrder.ExecuteBefore.Add(UE::Mass::ProcessorGroupNames::Avoidance);
}

void USimpleMoveToPlayerProcessor::ConfigureQueries()
{
	EntityQuery.AddRequirement<FTransformFragment>(EMassFragmentAccess::ReadWrite);
	EntityQuery.AddTagRequirement<FSimpleMoveToPlayerTag>(EMassFragmentPresence::All);
}

void USimpleMoveToPlayerProcessor::Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context)
{
	EntityQuery.ForEachEntityChunk(EntitySubsystem, Context, ([this](FMassExecutionContext& Context)
		{
			const TArrayView<FTransformFragment> TransformsList = Context.GetMutableFragmentView<FTransformFragment>();
			const float WorldDeltaTime = Context.GetDeltaTimeSeconds();

			for (int32 EntityIndex = 0; EntityIndex < Context.GetNumEntities(); ++EntityIndex)
			{
				FTransform& Transform = TransformsList[EntityIndex].GetMutableTransform();
				FVector PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

				FVector CurrentLocation = Transform.GetLocation();
				FVector TargetVector = PlayerLocation - CurrentLocation;

				if (TargetVector.Size() <= 20.f)
				{
					PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
				}
				else
				{
					Transform.SetLocation(CurrentLocation + TargetVector.GetSafeNormal() * 200.f * WorldDeltaTime);
				}
			}
		}));
}