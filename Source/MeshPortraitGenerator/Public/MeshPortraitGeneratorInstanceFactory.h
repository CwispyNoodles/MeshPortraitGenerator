// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MeshPortraitGeneratorInstanceFactory.generated.h"

/**
 * 
 */
UCLASS()
class MESHPORTRAITGENERATOR_API UMeshPortraitGeneratorInstanceFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UMeshPortraitGeneratorInstanceFactory(const FObjectInitializer& InObjectInitializer);

public: // UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
