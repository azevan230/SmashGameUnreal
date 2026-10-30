#include "AMatchGameModeBase.h"
#include "Arena/arenaPlayerStart.h"
#include "Kismet/GameplayStatics.h"

void AMatchGameModeBase::FindPlayerStartActorInArena(TArray<AArenaPlayerStart*>& ResultsActors)
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

void AMatchGameModeBase::BeginPlay()
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
	TSubclassOf<ASmashCharacter> AMatchGameModeBase::GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType) const
	{
		switch (InputType)
		{
		case EAutoReceiveInput::Player0:
			return SmashCharacterClassP0;
		case EAutoReceiveInput::Player1:
			return SmashCharacterClassP1;
		case EAutoReceiveInput::Player2:
			return SmashCharacterClassP2;
		case EAutoReceiveInput::Player3:
			return SmashCharacterClassP3;
		default:
			return nullptr;
		}
	}
}
