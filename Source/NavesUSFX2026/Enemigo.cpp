// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemigo.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AEnemigo::AEnemigo()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;

	// Simplificamos la ruta para evitar el error C2001 de Visual Studio
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaEnemigoNave(TEXT("/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid"));

	// Create the mesh component de forma correcta
	mallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	RootComponent = mallaEnemigo;

	mallaEnemigo->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	if (MallaEnemigoNave.Succeeded())
	{
		mallaEnemigo->SetStaticMesh(MallaEnemigoNave.Object);
	}
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	// ¡SE ELIMINÓ LA LÍNEA QUE CAUSABA EL CRASH AQUÍ!
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}