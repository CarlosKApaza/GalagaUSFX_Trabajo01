// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreadorNaves.h"
#include "CreadorNavesEnemigas.generated.h"

/**
 * 
 */
UCLASS()
class GALAGAUSFX_LAB06_API ACreadorNavesEnemigas : public ACreadorNaves
{
	GENERATED_BODY()
	
public:
	virtual ANaveEnemiga* CrearNaveEnemiga(FString NombreNaveSKU, FVector PosicionNave) override;
};
