// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshPortraitGenerator.h"

#include "IAssetTools.h"
#include "MeshPortraitGeneratorActions.h"

#define LOCTEXT_NAMESPACE "FMeshPortraitGeneratorModule"

void FMeshPortraitGeneratorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	IAssetTools& AssetTools = IAssetTools::Get();
	EAssetTypeCategories::Type AssetType = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("MeshPortraitGeneratorInstance")), LOCTEXT("MeshPortraitGeneratorInstanceCategory", "Mesh Portrait Generator"));
	TSharedPtr<FMeshPortraitGeneratorActions> MeshPortraitGeneratorActions = MakeShareable(new FMeshPortraitGeneratorActions(AssetType));

	AssetTools.RegisterAssetTypeActions(MeshPortraitGeneratorActions.ToSharedRef());
}

void FMeshPortraitGeneratorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMeshPortraitGeneratorModule, MeshPortraitGenerator)