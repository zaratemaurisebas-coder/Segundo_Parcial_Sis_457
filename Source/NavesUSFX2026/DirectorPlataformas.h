// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderPlataforma.h"
#include "DirectorPlataformas.generated.h"

UCLASS()
class NAVESUSFX2026_API ADirectorPlataformas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorPlataformas();
	void SetEscenarioBuilder(AActor* Builder);
	void ConstructEscenario(int32 CantAsteroides, int32 CantEnemigos);
	class AEscenarioEspacial* GetEscenario();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	IBuilderPlataforma* EscenarioBuilder;

};
