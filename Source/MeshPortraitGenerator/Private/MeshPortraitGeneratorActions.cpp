// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorActions.h"

#include "MeshPortraitGeneratorInstance.h"

#define LOCTEXT_NAMESPACE "MeshPortraitGeneratorActions"

FMeshPortraitGeneratorActions::FMeshPortraitGeneratorActions(EAssetTypeCategories::Type InAssetCategory)
	: AssetCategory(InAssetCategory)
{
}

FText FMeshPortraitGeneratorActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "MeshPortraitGeneratorActions", "Mesh Portrait Generator");
}

FColor FMeshPortraitGeneratorActions::GetTypeColor() const
{
	return FColor::Red;
}

UClass* FMeshPortraitGeneratorActions::GetSupportedClass() const
{
	return UMeshPortraitGeneratorInstance::StaticClass();
}

void FMeshPortraitGeneratorActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	FAssetTypeActions_Base::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}

uint32 FMeshPortraitGeneratorActions::GetCategories()
{
}

#undef LOCTEXT_NAMESPACE