#include "AnimGraphNode_EditBonePosition.h"
#include "CrewAnimUtilsEditor.h"

#define LOCTEXT_NAMESPACE "A3Nodes"

UAnimGraphNode_EditBonePosition::UAnimGraphNode_EditBonePosition() {}

FLinearColor UAnimGraphNode_EditBonePosition::GetNodeTitleColor() const
{
	return FLinearColor(0.1f, 0.0f, 0.1f);
}

FText UAnimGraphNode_EditBonePosition::GetTooltipText() const
{
	return LOCTEXT("EditBonePosition", "Edit Bone Position");
}

FText UAnimGraphNode_EditBonePosition::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("EditBonePosition", "Edit Bone Position");
}

FString UAnimGraphNode_EditBonePosition::GetNodeCategory() const
{
	return TEXT("CrewAnimUtils");
}

#undef LOCTEXT_NAMESPACE

