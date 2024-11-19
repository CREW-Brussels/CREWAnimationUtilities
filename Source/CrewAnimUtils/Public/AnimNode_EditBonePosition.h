#pragma once

#include "Animation/AnimNodeBase.h"
#include "BoneContainer.h"
#include "AnimNode_EditBonePosition.generated.h"

USTRUCT(BlueprintType)
struct FIgnoreVectorSettings
{
	GENERATED_BODY()
	FIgnoreVectorSettings() {
		IgnoreX = false;
		IgnoreY = false;
		IgnoreZ = false;
	}

	UPROPERTY(EditAnywhere, Category = "FIgnoreVectorSettings")
	bool IgnoreX;

	UPROPERTY(EditAnywhere, Category = "FIgnoreVectorSettings")
	bool IgnoreY;

	UPROPERTY(EditAnywhere, Category = "FIgnoreVectorSettings")
	bool IgnoreZ;
};

USTRUCT()
struct FBoneRef
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, Category = "Settings")
		FBoneReference Bone;
};

USTRUCT(BlueprintType)
struct CREWANIMUTILS_API FAnimNode_EditBonePosition : public FAnimNode_Base
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Links)
		FPoseLink BasePose;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (PinShownByDefault, BlueprintReadWrite))
		FVector Position;

	UPROPERTY(EditAnywhere, Category = "Settings")
		FIgnoreVectorSettings IgnorePosition;

	UPROPERTY(EditAnywhere, Category = "Settings")
		FBoneRef Bone;

public:

	FAnimNode_EditBonePosition();

	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext& Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext& Context) override;
	virtual void Evaluate_AnyThread(FPoseContext & Output) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
};
