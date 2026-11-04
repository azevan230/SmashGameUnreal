// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AMatchGameModeBase.generated.h"


class AArenaPlayerStart;
class ASmashCharacter;

UCLASS()
class SMASHUE_API AMatchGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
protected:
	UPROPERTY()
	TArray<ASmashCharacter*> CharactersInsideArena;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASmashCharacter> SmashCharacterClassP0;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASmashCharacter> SmashCharacterClassP1;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASmashCharacter> SmashCharacterClassP2;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASmashCharacter> SmashCharacterClassP3;
private :
	void FindPlayerStartActorInArena(TArray<AArenaPlayerStart*>& ResultActors);
	
	void SpawnCharacters(const TArray<AArenaPlayerStart*>& SpawnPoints);
	
	TSubclassOf<ASmashCharacter> GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType) const;	
};