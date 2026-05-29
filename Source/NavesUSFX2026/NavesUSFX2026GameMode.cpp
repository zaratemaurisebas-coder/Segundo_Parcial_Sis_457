// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX2026GameMode.h"
#include "NavesUSFX2026Pawn.h"
#include "GeneradorLaberinto.h"
#include "Engine/World.h"
#include "Bloque.h"
#include "Bonus.h" // Agrega esta línea al inicio del archivo para incluir la definición completa de ABonus
#include "DirectorPlataformas.h"
#include "FacadeEscenario.h"
#include "EscenarioEspacial.h"
#include "EnemigoAnimal.h"


ANavesUSFX2026GameMode::ANavesUSFX2026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ANavesUSFX2026Pawn::StaticClass();
    GeneradorLaberintoInstancia = CreateDefaultSubobject<AGeneradorLaberinto>(TEXT("GeneradorLaberinto"));

    //GeneradorLaberintoClass = AGeneradorLaberinto::StaticClass();
}

void ANavesUSFX2026GameMode::BeginPlay()
{
	Super::BeginPlay();
	
	
    if (!GetWorld())
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode: World no valido."));
        return;
    }

    /*
    if (!GeneradorLaberintoClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("GameMode: LaberintoGeneradorClass no esta asignada."));
        return;
    }*/
    FVector PosicionSpawn = FVector::ZeroVector;
    FRotator RotacionSpawn = FRotator::ZeroRotator;

    
    /*FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.SpawnCollisionHandlingOverride =
        ESpawnActorCollisionHandlingMethod::AlwaysSpawn;*/

    GeneradorLaberintoInstancia = GetWorld()->SpawnActor<AGeneradorLaberinto>(
        AGeneradorLaberinto::StaticClass(),
        PosicionSpawn,
        RotacionSpawn);

    if (GeneradorLaberintoInstancia)
    {
        UE_LOG(LogTemp, Warning, TEXT("GameMode: ALaberintoGenerador creado correctamente."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode: No se pudo crear ALaberintoGenerador."));
    }
    //GeneradorLaberintoInstancia->CrearBloquesEnEscena();

    //GeneradorLaberintoInstancia->ClasificarBloquesPorSector();

    for(int i = 0; i < 30; i++)
    {
        ABonus* BonusActual = ABonus::GetInstancia(GetWorld());
        UE_LOG(LogTemp, Warning, TEXT("GameMode: Bloque %d en posicion (%f, %f, %f)"), i, BonusActual->GetActorLocation().X, BonusActual->GetActorLocation().Y, BonusActual->GetActorLocation().Z);
	}

	
    ADirectorPlataformas* Director = GetWorld()->SpawnActor<ADirectorPlataformas>(ADirectorPlataformas::StaticClass());
    AFacadeEscenario* ConstructorEscenario = GetWorld()->SpawnActor<AFacadeEscenario>(AFacadeEscenario::StaticClass());

    if (Director && ConstructorEscenario)
    {
        // 3. Vinculamos el constructor al director
        Director->SetEscenarioBuilder(ConstructorEscenario);

        // 4. El director ordena la construcción con los parámetros deseados
        // Ejemplo: Creamos un escenario espacial con 15 asteroides y 6 enemigos
        Director->ConstructEscenario(15, 6);

        // 5. El director nos devuelve el producto complejo terminado
        AEscenarioEspacial* EscenarioFinal = Director->GetEscenario();
        if (EscenarioFinal)
        {
            // Imprime el Log en pantalla confirmando la creación física exitosa
            EscenarioFinal->MostrarEscenario();
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("GameMode: No se pudieron inicializar los componentes del Builder."));
    }
}


