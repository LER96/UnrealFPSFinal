// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyTest.generated.h"

UCLASS()
class UNREAL102_FPS_FINAL_API AEnemyTest : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	AEnemyTest();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "AI")
	bool SeeingPlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
