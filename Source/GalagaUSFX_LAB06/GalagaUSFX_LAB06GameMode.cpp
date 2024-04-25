// Copyright Epic Games, Inc. All Rights Reserved.

#include "GalagaUSFX_LAB06GameMode.h"
#include "GalagaUSFX_LAB06Pawn.h"

#include "CreadorNaves.h"
#include "CreadorNavesEnemigas.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaBombardero.h"

AGalagaUSFX_LAB06GameMode::AGalagaUSFX_LAB06GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalagaUSFX_LAB06Pawn::StaticClass();
}

void AGalagaUSFX_LAB06GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Creando las naves enemigas
	ACreadorNaves* CreadorNaves = GetWorld()->SpawnActor<ACreadorNavesEnemigas>(ACreadorNavesEnemigas::StaticClass());

	// Definiendo las posiciones de las naves enemigas
	FVector	PosicionNaveInicial = FVector (-600.0f, 0.0f, 180.0f);

	UWorld * World = GetWorld();
	if (World != nullptr) 
	{
		// spawneado las naves enemigas caza
		for (int i = 0; i < 7; i++)
		{
			ANaveEnemiga* NaveEnemiga = CreadorNaves->OrdenarNave("NaveEnemigaCaza", PosicionNaveInicial);
			TANavesEnemigas.Add(NaveEnemiga);
			PosicionNaveInicial.Y += 160.0f;
		}

		// Actualizar la ubicación inicial para las naves de la clase bombardero
		PosicionNaveInicial.X = PosicionNaveInicial.X = -400.0f; // crear un fila por el medio
		PosicionNaveInicial.Y = PosicionNaveInicial.Y = 0.0f; // actualizo la creacion de la nave enemiga bombardero

		for (int i =0; i < 7; i++)
		{
			ANaveEnemiga* NaveEnemiga = CreadorNaves->OrdenarNave("NaveEnemigaBombardero", PosicionNaveInicial);
			TANavesEnemigas.Add(NaveEnemiga);
			PosicionNaveInicial.Y += 160.0f;
		}
		// Actualizar la ubicación inicial para las naves de la clase bombardero
		PosicionNaveInicial.X = PosicionNaveInicial.X = -200.0f; // crear un fila por el medio
		PosicionNaveInicial.Y = PosicionNaveInicial.Y = 0.0f; // actualizo la creacion de la nave enemiga bombardero

		for (int i = 0; i < 7; i++)
		{
			ANaveEnemiga* NaveEnemiga = CreadorNaves->OrdenarNave("NaveEnemigaEspia", PosicionNaveInicial);
			TANavesEnemigas.Add(NaveEnemiga);
			PosicionNaveInicial.Y += 160.0f;
		}
		// Actualizar la ubicación inicial para las naves de la clase bombardero
		PosicionNaveInicial.X = PosicionNaveInicial.X = 0.0f; // crear un fila por el medio
		PosicionNaveInicial.Y = PosicionNaveInicial.Y = 0.0f; // actualizo la creacion de la nave enemiga bombardero

		for (int i = 0; i < 7; i++)
		{
			ANaveEnemiga* NaveEnemiga = CreadorNaves->OrdenarNave("NaveEnemigaTransporte", PosicionNaveInicial);
			TANavesEnemigas.Add(NaveEnemiga);
			PosicionNaveInicial.Y += 160.0f;
		}
	}
}


