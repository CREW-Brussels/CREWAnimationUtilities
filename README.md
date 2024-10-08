# CREWAnimationUtilities

This UnrealEngine plugin contains utilities used by CREW to solve common problems when dealing with real-time VR performances.

At this point it contains one animation node 

# EditBonePosition
EditBonePosition is intended to modify the position of a bone in a skeletal mesh.
We use it to compensate the drift of a Xsens motion tracking system by attaching a more accurate sensor (in terms of absolute position) to the pelvis of the actor.

In this case we only need to correct the x and y coordinates of the pelvis bone.
![EditBonePositionSettings](https://github.com/CREW-Brussels/CREWAnimationUtilities/assets/6745738/b3125724-6183-4dd8-9594-3d33da8e23c7)

After correcting the offset and orientation of the tracker, it's position can be directly applied to the pelvis bone of the skeletal mesh.
![ExempleBluePrint](https://github.com/CREW-Brussels/CREWAnimationUtilities/assets/6745738/6421679b-c993-4ec1-914d-26669ff1b608)
