
#include "AnimNode_EditBonePosition.h"
#include "AnimationRuntime.h"
#include "Animation/AnimInstanceProxy.h"
 
FAnimNode_EditBonePosition::FAnimNode_EditBonePosition() {}

void FAnimNode_EditBonePosition::Initialize_AnyThread(const FAnimationInitializeContext & Context)
{
	FAnimNode_Base::Initialize_AnyThread(Context);
	BasePose.Initialize(Context);
	const FBoneContainer& BoneContainer = Context.AnimInstanceProxy->GetRequiredBones();
	if (!Bone.Bone.IsValidToEvaluate())
		FBoneReference(FName("pelvis")).Initialize(BoneContainer);
	else
		Bone.Bone.Initialize(BoneContainer);
}

void FAnimNode_EditBonePosition::CacheBones_AnyThread(const FAnimationCacheBonesContext & Context)
{
	BasePose.CacheBones(Context);
}

void FAnimNode_EditBonePosition::Update_AnyThread(const FAnimationUpdateContext & Context)
{
	GetEvaluateGraphExposedInputs().Execute(Context);
	BasePose.Update(Context);
}

void FAnimNode_EditBonePosition::Evaluate_AnyThread(FPoseContext& Output)
{
	BasePose.Evaluate(Output);

	const FBoneContainer& BoneContainer = Output.AnimInstanceProxy->GetRequiredBones();

	BasePose.Evaluate(Output);

	FComponentSpacePoseContext CSOutput(Output.AnimInstanceProxy);
	CSOutput.Pose.InitPose(Output.Pose);

	FCompactPoseBoneIndex PelvisBoneIndex(1);

	FTransform TheBone = CSOutput.Pose.GetComponentSpaceTransform(PelvisBoneIndex);

	FVector OriginalPosition = TheBone.GetLocation();
	FVector TargetPosition = {
		IgnorePosition.IgnoreX ? OriginalPosition.X : Position.X,
		IgnorePosition.IgnoreY ? OriginalPosition.Y : Position.Y,
		IgnorePosition.IgnoreZ ? OriginalPosition.Z : Position.Z
	};
	Output.Pose[PelvisBoneIndex].SetLocation(TargetPosition);
	
}

void FAnimNode_EditBonePosition::GatherDebugData(FNodeDebugData & DebugData)
{
	FString DebugLine = DebugData.GetNodeName(this);

	DebugData.AddDebugItem(DebugLine);

	BasePose.GatherDebugData(DebugData);
}
