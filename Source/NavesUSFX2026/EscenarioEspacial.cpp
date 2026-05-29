// Fill out your copyright notice in the Description page of Project Settings.


#include "EscenarioEspacial.h"
#include "Enemigo.h"
#include "Engine/Engine.h"

// Sets default values
AEscenarioEspacial::AEscenarioEspacial()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AEscenarioEspacial::BeginPlay()
{
	Super::BeginPlay();
	
}
void AEscenarioEspacial::SetCantidadAsteroides(int32 Cantidad) { CantidadAsteroides = Cantidad; }
void AEscenarioEspacial::SetCantidadEnemigos(int32 Cantidad) { CantidadEnemigos = Cantidad; }
void AEscenarioEspacial::AgregarAsteroide(ABloque* Bloque)
{
	if (Bloque) Asteroides.Add(Bloque);
}

void AEscenarioEspacial::AgregarEnemigo(AEnemigo* Enemigo)
{
	if (Enemigo) Enemigos.Add(Enemigo);
}
void AEscenarioEspacial::MostrarEscenario()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan,
			FString::Printf(TEXT("Escenario Espacial Terminado -> Asteroides: %d | Enemigos: %d"), Asteroides.Num(), Enemigos.Num()));
	}
}