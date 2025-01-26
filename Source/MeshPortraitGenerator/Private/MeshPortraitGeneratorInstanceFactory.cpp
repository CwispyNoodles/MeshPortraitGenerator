// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorInstanceFactory.h"

#include "MeshPortraitGeneratorInstance.h"

UMeshPortraitGeneratorInstanceFactory::UMeshPortraitGeneratorInstanceFactory(const FObjectInitializer& InObjectInitializer)
	: Super(InObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UMeshPortraitGeneratorInstance::StaticClass();
}

UObject* UMeshPortraitGeneratorInstanceFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMeshPortraitGeneratorInstance* NewMeshPortraitGeneratorInstance = NewObject<UMeshPortraitGeneratorInstance>(InParent, InName, Flags);
	return NewMeshPortraitGeneratorInstance;
}
