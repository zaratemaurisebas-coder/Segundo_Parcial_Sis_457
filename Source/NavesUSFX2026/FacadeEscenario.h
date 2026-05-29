// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderPlataforma.h"
#include "EscenarioEspacial.h"
#include "FacadeEscenario.generated.h"

UCLASS()
class NAVESUSFX2026_API AFacadeEscenario :public AActor, public IBuilderPlataforma
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacadeEscenario();
	// Implementación obligatoria de los pasos de la interfaz
	virtual void BuildAsteroides(int32 Cantidad) override;
	virtual void BuildEnemigos(int32 Cantidad) override;
	virtual AEscenarioEspacial* GetEscenario() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	AEscenarioEspacial* Escenario;

	// Configuración del área tridimensional donde aparecerá el escenario espacial
	FVector CentroEspacial = FVector(0.f, 0.f, 250.f);
	FVector DimensionesArea = FVector(1200.f, 1200.f, 0.f);
};
