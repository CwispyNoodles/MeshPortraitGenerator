// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorEditor.h"

void FMeshPortraitGeneratorEditor::InitMeshPortraitGeneratorEditor(const EToolkitMode::Type Mode,
	const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* InObject)
{
}

void FMeshPortraitGeneratorEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

FName FMeshPortraitGeneratorEditor::GetToolkitFName() const
{
}

FText FMeshPortraitGeneratorEditor::GetBaseToolkitName() const
{
}

FString FMeshPortraitGeneratorEditor::GetWorldCentricTabPrefix() const
{
}

FLinearColor FMeshPortraitGeneratorEditor::GetWorldCentricTabColorScale() const
{
}

FString FMeshPortraitGeneratorEditor::GetDocumentationLink() const
{
	return FWorkflowCentricApplication::GetDocumentationLink();
}

void FMeshPortraitGeneratorEditor::OnToolkitHostingStarted(const TSharedRef<IToolkit>& Toolkit)
{
	FWorkflowCentricApplication::OnToolkitHostingStarted(Toolkit);
}

void FMeshPortraitGeneratorEditor::OnToolkitHostingFinished(const TSharedRef<IToolkit>& Toolkit)
{
	FWorkflowCentricApplication::OnToolkitHostingFinished(Toolkit);
}
