// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class UMeshPortraitGeneratorInstance;
/**
 * 
 */
class MESHPORTRAITGENERATOR_API FMeshPortraitGeneratorEditor : public FWorkflowCentricApplication, public FEditorUndoClient, public FNotifyHook
{

public:
	void InitMeshPortraitGeneratorEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);
	UMeshPortraitGeneratorInstance* GetWorkingAsset() const { return WorkingAsset; }

private:
	TObjectPtr<UMeshPortraitGeneratorInstance> WorkingAsset = nullptr;
	
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
