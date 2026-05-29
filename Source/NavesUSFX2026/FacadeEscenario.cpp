// Fill out your copyright notice in the Description page of Project Settings.


#include "FacadeEscenario.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "Engine/World.h"

// Sets default values
AFacadeEscenario::AFacadeEscenario()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AFacadeEscenario::BeginPlay()
{
	Super::BeginPlay();
	// Al iniciar, el constructor instancia el producto base vacío tal como dicta el libro
	Escenario = GetWorld()->SpawnActor<AEscenarioEspacial>(AEscenarioEspacial::StaticClass());
}

void AFacadeEscenario::BuildAsteroides(int32 Cantidad)
{
	if (!Escenario) return;
	Escenario->SetCantidadAsteroides(Cantidad);

	for (int32 i = 0; i < Cantidad; ++i)
	{
		FVector PosicionRand(
			CentroEspacial.X + FMath::FRandRange(-DimensionesArea.X, DimensionesArea.X),
			CentroEspacial.Y + FMath::FRandRange(-DimensionesArea.Y, DimensionesArea.Y),
			CentroEspacial.Z
		);
		ABloque* AsteroideFisico = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), PosicionRand, FRotator::ZeroRotator);
		if (AsteroideFisico != nullptr)
		{
			Escenario->AgregarAsteroide(AsteroideFisico);
		}
	}
}

void AFacadeEscenario::BuildEnemigos(int32 Cantidad)
{
	if (!Escenario) return;
	Escenario->SetCantidadEnemigos(Cantidad);

	for (int32 i = 0; i < Cantidad; ++i)
	{
		FVector PosicionRand(
			CentroEspacial.X + FMath::FRandRange(-DimensionesArea.X, DimensionesArea.X),
			CentroEspacial.Y + FMath::FRandRange(-DimensionesArea.Y, DimensionesArea.Y),
			CentroEspacial.Z
		);
		AEnemigo* NaveEnemigaFisica = GetWorld()->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), PosicionRand, FRotator::ZeroRotator);

		if (NaveEnemigaFisica != nullptr)
		{
			Escenario->AgregarEnemigo(NaveEnemigaFisica);
		}
	}
}

AEscenarioEspacial* AFacadeEscenario::GetEscenario()
{
	return Escenario;
}

