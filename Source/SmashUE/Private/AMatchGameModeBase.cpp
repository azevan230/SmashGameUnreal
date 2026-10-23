#include "AMatchGameModeBase.h"
#include "Arena/arenaPlayerStart.h"
#include "Kismet/GameplayStatics.h"

void AAMatchGameModeBase::FindPlayerStartActorInArena(TArray<AArenaPlayerStart*>& ResultsActors)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AArenaPlayerStart::StaticClass() ,FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		AArenaPlayerStart* ArenaPlayerStartActor = Cast<AArenaPlayerStart>(FoundActors[i]);
		if (!ArenaPlayerStartActor) continue;
		
		ResultsActors.Add(ArenaPlayerStartActor);
	}
}

void AAMatchGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AArenaPlayerStart*> PlayerStartPoints;
	FindPlayerStartActorInArena(PlayerStartPoints);
	
	for (AArenaPlayerStart* PlayerStartPoint : PlayerStartPoints)
	{
		GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Cyan,
		PlayerStartPoint->GetFName().ToString()
		);	
	}
}
