// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorEditorMode.h"

#include "MeshPortraitGeneratorViewportTabSummoner.h"

FMeshPortraitGeneratorEditorMode::FMeshPortraitGeneratorEditorMode(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor)
	: FApplicationMode(TEXT("MeshPortraitGeneratorEditorMode"))
{
	
}

void FMeshPortraitGeneratorEditorMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FMeshPortraitGeneratorEditorMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
}

void FMeshPortraitGeneratorEditorMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
}
