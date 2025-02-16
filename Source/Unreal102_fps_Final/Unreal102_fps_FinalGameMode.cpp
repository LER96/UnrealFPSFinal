// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal102_fps_FinalGameMode.h"
#include "Unreal102_fps_FinalCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include "Kismet/GameplayStatics.h"
#include "Enemy.h"
#include "EnemyTest.h"

AUnreal102_fps_FinalGameMode::AUnreal102_fps_FinalGameMode() : Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PrimaryActorTick.bCanEverTick = true;

}

void AUnreal102_fps_FinalGameMode::BeginPlay()
{
	//find players
	PlayerCharacter = Cast<AUnreal102_fps_FinalCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//find all enemies
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTest::StaticClass(), FoundActors);

	EnemyActors.Empty();

	for (AActor* Actor : FoundActors)
	{
		AEnemyTest* Enemy = Cast<AEnemyTest>(Actor);
		if (Enemy)
		{
			EnemyActors.Add(Enemy);
		}
	}
}

void AUnreal102_fps_FinalGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GameOver)
		return;

	if (PlayerCharacter)
	{
		if (AnyEnemySeeingPlayer())
		{
			PlayerCharacter->IncreaseDetection(DeltaTime);
		}
		else
			PlayerCharacter->DecreaseDetection(DeltaTime);

		if (PlayerCharacter->Detected)
			EndGame(false);
	}
}

bool AUnreal102_fps_FinalGameMode::AnyEnemySeeingPlayer()
{
	for (AEnemyTest* Enemy : EnemyActors)
	{
		if (Enemy->SeeingPlayer)
			return true;
	}
	return false;
}

void AUnreal102_fps_FinalGameMode::EndGame(bool bwin)
{
	GameOver = true;
	OnGameEnd(bwin);
}

bool AUnreal102_fps_FinalGameMode::GetGameOver()
{
	return GameOver;
}
