// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EscenarioEspacial.h"
#include "BuilderPlataforma.generated.h"

// This class does not need to be modified.

class AEscenarioEspacial;
UINTERFACE(MinimalAPI)
class UBuilderPlataforma : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class NAVESUSFX2026_API IBuilderPlataforma
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void BuildAsteroides(int32 Cantidad) = 0;
	virtual void BuildEnemigos(int32 Cantidad) = 0;

	// Método para obtener el resultado final complejo
	virtual AEscenarioEspacial* GetEscenario() = 0;
};
