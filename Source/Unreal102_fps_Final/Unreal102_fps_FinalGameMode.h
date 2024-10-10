// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
//#include "Enemy.h"
#include "EnemyTest.h"
#include "Unreal102_fps_FinalGameMode.generated.h"

UCLASS(minimalapi)
class AUnreal102_fps_FinalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnreal102_fps_FinalGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Detection")
	bool AnyEnemySeeingPlayer();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Detection")
	class AUnreal102_fps_FinalCharacter* PlayerCharacter;

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnGameEnd(bool bwin);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameMode")
	bool GameOver;

private:
	TArray<AEnemyTest*> EnemyActors;
};



