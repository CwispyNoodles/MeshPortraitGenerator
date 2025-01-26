// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FMeshPortraitGeneratorEditor;
/**
 * 
 */
class FMeshPortraitGeneratorDetailsTabSummoner : public FWorkflowTabFactory
{
public:
	FMeshPortraitGeneratorDetailsTabSummoner(TSharedPtr<FMeshPortraitGeneratorEditor> InEditor);

private:
	TWeakPtr<FMeshPortraitGeneratorEditor> MeshPortraitGeneratorEditor;

public: // FWorkflowTabFactory Interface
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
};
