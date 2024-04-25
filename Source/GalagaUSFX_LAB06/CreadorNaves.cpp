// Fill out your copyright notice in the Description page of Project Settings.


#include "CreadorNaves.h"

// Sets default values
ACreadorNaves::ACreadorNaves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreadorNaves::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACreadorNaves::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ANaveEnemiga* ACreadorNaves::OrdenarNave(FString Categotia, FVector UbicacionNaveOrden)
{
	// Crea la nave y registra su nombre
	ANaveEnemiga* NaveEnemiga = CrearNaveEnemiga(Categotia, UbicacionNaveOrden);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Creando %s"), *NaveEnemiga->GetNombreNave()));
	/*GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Construyendo la nave..."));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Colocando materiales... "));*/

	// Retorna la nave creada
	return NaveEnemiga;
}

