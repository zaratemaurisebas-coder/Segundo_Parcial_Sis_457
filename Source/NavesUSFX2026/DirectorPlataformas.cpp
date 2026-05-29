// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorPlataformas.h"
#include "EscenarioEspacial.h"

// Sets default values
ADirectorPlataformas::ADirectorPlataformas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	EscenarioBuilder = nullptr;
}

// Called when the game starts or when spawned
void ADirectorPlataformas::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADirectorPlataformas::SetEscenarioBuilder(AActor* Builder)
{
	// Cast dinámico seguro nativo de Unreal Engine para interactuar con la interfaz
	EscenarioBuilder = Cast<IBuilderPlataforma>(Builder);
}

void ADirectorPlataformas::ConstructEscenario(int32 CantAsteroides, int32 CantEnemigos)
{
	if (EscenarioBuilder)
	{
		// El Director dicta de forma estricta la secuencia del algoritmo
		EscenarioBuilder->BuildAsteroides(CantAsteroides);
		EscenarioBuilder->BuildEnemigos(CantEnemigos);
	}
}

AEscenarioEspacial* ADirectorPlataformas::GetEscenario()
{
	if (EscenarioBuilder)
	{
		return EscenarioBuilder->GetEscenario();
	}
	return nullptr;
}

