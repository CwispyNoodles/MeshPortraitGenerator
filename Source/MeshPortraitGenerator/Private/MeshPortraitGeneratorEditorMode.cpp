// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorEditorMode.h"

#include "MeshPortraitGeneratorEditor.h"
#include "MeshPortraitGeneratorViewportTabSummoner.h"

FMeshPortraitGeneratorEditorMode::FMeshPortraitGeneratorEditorMode(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor)
	: FApplicationMode(TEXT("MeshPortraitGeneratorEditorMode"))
{
	MeshPortraitGeneratorEditor = InEditor;
	Tabs.RegisterFactory(MakeShared<FMeshPortraitGeneratorViewportTabSummoner>(InEditor));

	TabLayout = FTabManager::NewLayout("MeshPortraitGenerator_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea()
		->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewSplitter()
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.75f)
				->AddTab(FName(TEXT("MeshPortraitGeneratorViewportTabId")), ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.25f)
				->AddTab(FName(TEXT("MeshPortraitGeneratorViewportTabId")), ETabState::OpenedTab)
			)
		)
	);
}

void FMeshPortraitGeneratorEditorMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	TSharedPtr<FMeshPortraitGeneratorEditor> Editor = MeshPortraitGeneratorEditor.Pin();
	Editor->PushTabFactories(Tabs);
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
