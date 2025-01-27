// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCommonEditorViewportToolbarBase.h"
#include "SEditorViewport.h"

class FAdvancedPreviewScene;
class UMeshPortraitGeneratorInstance;
/**
 * 
 */
class SMeshPortraitGeneratorViewport : public SEditorViewport, public ICommonEditorViewportToolbarInfoProvider
{
public:
	SLATE_BEGIN_ARGS(SMeshPortraitGeneratorViewport) : _EditingObject(nullptr) {}
		SLATE_ARGUMENT(UMeshPortraitGeneratorInstance*, EditingObject)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:
	TSharedPtr<FEditorViewportClient> LevelViewportClient;
	TSharedPtr<FAdvancedPreviewScene> AdvancedPreviewScene = nullptr;
	TObjectPtr<UMeshPortraitGeneratorInstance> WorkingAsset;

protected: // SEditorViewport Interface
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

public: // ICommonEditorViewportToolbarInfoProvider Interface
	virtual TSharedRef<SEditorViewport> GetViewportWidget() override { return SharedThis(this); }
	virtual TSharedPtr<FExtender> GetExtenders() const override { return MakeShareable(new FExtender); }
	virtual void OnFloatingButtonClicked() override {}

	
};
