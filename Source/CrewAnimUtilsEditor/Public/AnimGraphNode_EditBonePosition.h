#pragma once

#include "CoreMinimal.h"
#include "AnimGraphNode_Base.h"
#include "AnimNode_EditBonePosition.h"
#include "AnimGraphNode_EditBonePosition.generated.h"

struct FAnimNode_EditBonePosition;

UCLASS()
class CREWANIMUTILSEDITOR_API UAnimGraphNode_EditBonePosition : public UAnimGraphNode_Base
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Settings")
	FAnimNode_EditBonePosition Node;

	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual FString GetNodeCategory() const override;

	UAnimGraphNode_EditBonePosition();
};
