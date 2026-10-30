// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

class AArenaPlayerStart;
class ASmashCharacter;

UCLASS()
class SMASHUE_API AMatchGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
protected:
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
	
	TSubclassOf<ASmashCharacter> GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType) const;	
};

#include "AMatchGameModeBase.generated.h"

/**
 * 
 */