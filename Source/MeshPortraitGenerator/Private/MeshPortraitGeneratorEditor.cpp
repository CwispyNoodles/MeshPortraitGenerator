// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorEditor.h"

#define LOCTEXT_NAMESPACE "MeshPortraitGeneratorEditor"

void FMeshPortraitGeneratorEditor::InitMeshPortraitGeneratorEditor(const EToolkitMode::Type Mode,
	const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* InObject)
{
	TArray<UObject*> ObjectsToEdit;
	ObjectsToEdit.Add(InObject);
	
	InitAssetEditor
	(
		Mode,
		InitToolkitHost,
		TEXT("MeshPortraitGeneratorEditor"),
		FTabManager::FLayout::NullLayout,
		true,
		true,
		ObjectsToEdit
	);

	
}

void FMeshPortraitGeneratorEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

FName FMeshPortraitGeneratorEditor::GetToolkitFName() const
{
	return FName("FMeshPortraitGeneratorEditor");
}

FText FMeshPortraitGeneratorEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "Mesh Portrait Generator Editor");
}

FString FMeshPortraitGeneratorEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("MeshPortraitGeneratorEditor");
}

FLinearColor FMeshPortraitGeneratorEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::White;
}

FString FMeshPortraitGeneratorEditor::GetDocumentationLink() const
{
	return TEXT("https://github.com/CwispyNoodles/MeshPortraitGenerator");
}

void FMeshPortraitGeneratorEditor::OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit)
{
	FWorkflowCentricApplication::OnToolkitHostingStarted(Toolkit);
}

void FMeshPortraitGeneratorEditor::OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit)
{
	FWorkflowCentricApplication::OnToolkitHostingFinished(Toolkit);
}

#undef LOCTEXT_NAMESPACE