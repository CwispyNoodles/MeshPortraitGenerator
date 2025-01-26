// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FMeshPortraitGeneratorEditor;
/**
 * 
 */
class FMeshPortraitGeneratorEditorMode : FApplicationMode
{
public:
	FMeshPortraitGeneratorEditorMode(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor);

private:
	TWeakPtr<FMeshPortraitGeneratorEditor> MeshPortraitGeneratorEditor;
	FWorkflowAllowedTabSet Tabs;

public: // FApplicationMode Interface
	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;
};
