// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorDetailsTabSummoner.h"
#include "MeshPortraitGeneratorEditor.h"
#include "MeshPortraitGeneratorInstance.h"

#define LOCTEXT_NAMESPACE "MeshPortraitGeneratorDetailsTabSummoner"

const FName MeshPortraitGeneratorDetailsTabId = FName(TEXT("MeshPortraitGeneratorTabId"));

FMeshPortraitGeneratorDetailsTabSummoner::FMeshPortraitGeneratorDetailsTabSummoner(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor)
	: FWorkflowTabFactory(MeshPortraitGeneratorDetailsTabId, InEditor)
{
	MeshPortraitGeneratorEditor = InEditor;
	TabLabel = LOCTEXT("DialogueDetailsTabLabel", "Details");
	ViewMenuDescription = LOCTEXT("DialogueDetails_ViewMenu_Desc", "Details");
	ViewMenuTooltip = LOCTEXT("DialogueDetails_ViewMenu_ToolTip", "Show the Details");
}

TSharedRef<SWidget> FMeshPortraitGeneratorDetailsTabSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FMeshPortraitGeneratorEditor> Editor = MeshPortraitGeneratorEditor.Pin();
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

	FDetailsViewArgs DetailsViewArgs;
	{
		DetailsViewArgs.bAllowSearch = false;
		DetailsViewArgs.bHideSelectionTip = true;
		DetailsViewArgs.bLockable = false;
		DetailsViewArgs.bSearchInitialKeyFocus = true;
		DetailsViewArgs.bUpdatesFromSelection = false;
		DetailsViewArgs.NotifyHook = nullptr;
		DetailsViewArgs.bShowOptions = true;
		DetailsViewArgs.bShowModifiedPropertiesOption = false;
		DetailsViewArgs.bShowScrollBar = false;
	}

	TSharedPtr<IDetailsView> SelectedNodeDetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	SelectedNodeDetailsView->SetObject(Editor->GetWorkingAsset());

	return SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.FillHeight(1.0f)
				.HAlign(HAlign_Fill)
				[
					SelectedNodeDetailsView.ToSharedRef()
				];
}

FText FMeshPortraitGeneratorDetailsTabSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FWorkflowTabFactory::GetTabToolTipText(Info);
}

#undef LOCTEXT_NAMESPACE