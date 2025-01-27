// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorViewportTabSummoner.h"
#include "MeshPortraitGeneratorEditor.h"
#include "SMeshPortraitGeneratorViewport.h"

#define LOCTEXT_NAMESPACE "MeshPortraitGeneratorViewportTabSummoner"

const FName MeshPortraitGeneratorViewportTabId = FName(TEXT("MeshPortraitGeneratorViewportTabId"));

FMeshPortraitGeneratorViewportTabSummoner::FMeshPortraitGeneratorViewportTabSummoner(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor)
	: FWorkflowTabFactory(MeshPortraitGeneratorViewportTabId, InEditor)
{
	MeshPortraitGeneratorEditor = InEditor;
	TabLabel = LOCTEXT("MeshPortraitGeneratorViewportTabLabel", "Viewport");
	ViewMenuDescription = LOCTEXT("MeshPortraitGenerator_ViewMenu_Desc", "Mesh Portrait Generator Viewport");
	ViewMenuTooltip = LOCTEXT("MeshPortraitGenerator_Viewmenu_ToolTip", "Show the Viewport");
}

TSharedRef<SWidget> FMeshPortraitGeneratorViewportTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FMeshPortraitGeneratorEditor> Editor = MeshPortraitGeneratorEditor.Pin();
	return SNew(SOverlay)
	+SOverlay::Slot()
	[
		SNew(SMeshPortraitGeneratorViewport)
		.EditingObject(Editor->GetWorkingAsset())
	];
}

FText FMeshPortraitGeneratorViewportTabSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FWorkflowTabFactory::GetTabToolTipText(Info);
}

#undef LOCTEXT_NAMESPACE