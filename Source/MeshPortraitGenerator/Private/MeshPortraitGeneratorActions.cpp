// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshPortraitGeneratorActions.h"

#include "MeshPortraitGeneratorEditor.h"
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
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if (UMeshPortraitGeneratorInstance* MeshPortraitGeneratorInstance = Cast<UMeshPortraitGeneratorInstance>(*ObjIt))
		{
			TSharedRef<FMeshPortraitGeneratorEditor> NewGraphEditor(new FMeshPortraitGeneratorEditor());
			NewGraphEditor->InitMeshPortraitGeneratorEditor(Mode, EditWithinLevelEditor, MeshPortraitGeneratorInstance);
		}
	}
}

uint32 FMeshPortraitGeneratorActions::GetCategories()
{
	return AssetCategory;
}

#undef LOCTEXT_NAMESPACE