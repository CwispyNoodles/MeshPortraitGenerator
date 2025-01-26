// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"
#include "MeshPortraitGeneratorEditor.generated.h"

/**
 * 
 */
class MESHPORTRAITGENERATOR_API FMeshPortraitGeneratorEditor : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{

public:
	void InitMeshPortraitGeneratorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);
public: // FAssetEditorToolkit interface
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FString GetDocumentationLink() const override;
	virtual void OnToolkitHostingStarted(const TSharedRef<class IToolkit>& Toolkit) override;
	virtual void OnToolkitHostingFinished(const TSharedRef<class IToolkit>& Toolkit) override;
};
