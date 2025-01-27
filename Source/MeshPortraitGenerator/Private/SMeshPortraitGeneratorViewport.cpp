// Fill out your copyright notice in the Description page of Project Settings.


#include "SMeshPortraitGeneratorViewport.h"

#include "AdvancedPreviewScene.h"


void SMeshPortraitGeneratorViewport::Construct(const FArguments& InArgs)
{
	// We need to create a new Scene prior to constructing the Viewport.
	// Otherwise, it will default to grabbing the one from the main World in the Editor.
	AdvancedPreviewScene = MakeShareable(new FAdvancedPreviewScene(FPreviewScene::ConstructionValues()));

	SEditorViewport::Construct(SEditorViewport::FArguments());

	WorkingAsset = InArgs._EditingObject;

	if (!WorkingAsset)
	{
		UE_LOG(LogTemp, Error, TEXT("SMeshPortraitGeneratorViewport::Construct: WorkingAsset is not Valid!"));
		return;
	}

	// For Reference:
	// ABuildingBase* PreviewBuilding = GetWorld()->SpawnActor<ABuildingBase>();
	// PreviewBuilding->BuildingStyle = StylePreset.Get();
	// PreviewBuilding->RerunConstructionScripts();
}

TSharedRef<FEditorViewportClient> SMeshPortraitGeneratorViewport::MakeEditorViewportClient()
{
	LevelViewportClient = MakeShareable(new FEditorViewportClient(nullptr, AdvancedPreviewScene.Get(), SharedThis(this)));

	LevelViewportClient->ViewportType = LVT_Perspective;
	LevelViewportClient->SetRealtime(true);

	LevelViewportClient->SetViewLocation(FVector(-5000.0f, 0.0f, 500.0f));
	LevelViewportClient->SetViewRotation(FRotator(-30.0f, -90.0f, 0.0f));

	return LevelViewportClient.ToSharedRef();
}

