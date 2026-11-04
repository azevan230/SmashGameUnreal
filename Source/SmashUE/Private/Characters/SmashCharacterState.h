
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmashCharacterStateID.h"
#include "SmashCharacterState.generated.h"



class ASmashCharacter;
class USmashCharacterStateMachine;

UCLASS(Abstract)
class USmashCharacterState : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USmashCharacterState();
	
	virtual ESmashCharacterStateID GetStateID();
	
	virtual void StateInit(USmashCharacterStateMachine* InStateMachine);
	
	virtual void StateEnter(ESmashCharacterStateID PreviousStateID);
	
	virtual void StateExit(ESmashCharacterStateID NextStateID);
	
	virtual void StateTick(float DeltaTime);

	
protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;
	
	UPROPERTY()
	TObjectPtr<USmashCharacterStateMachine> StateMachine;
};
