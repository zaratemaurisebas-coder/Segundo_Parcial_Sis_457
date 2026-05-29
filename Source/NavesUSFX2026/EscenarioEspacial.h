// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.h"
#include "EscenarioEspacial.generated.h"

class AEnemigo;
UCLASS()
class NAVESUSFX2026_API AEscenarioEspacial : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscenarioEspacial();
	// Métodos que utiliza el Builder Concreto para setear características
	void SetCantidadAsteroides(int32 Cantidad);
	void SetCantidadEnemigos(int32 Cantidad);
	void AgregarAsteroide(ABloque* Bloque);
	void AgregarEnemigo(AEnemigo* Enemigo);

	void MostrarEscenario();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int32 CantidadAsteroides = 0;
	int32 CantidadEnemigos = 0;

	UPROPERTY()
	TArray<ABloque*> Asteroides;

	UPROPERTY()
	TArray<AEnemigo*> Enemigos;
};
