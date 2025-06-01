# CREWAnimationUtilities

This UnrealEngine plugin contains utilities used by CREW to solve common problems when dealing with real-time VR performances.

At this point it contains one animation node 

***
Requirements:
- Unreal Engine 5.3
- [Download](https://github.com/CREW-Brussels/CREWAnimationUtilities) the plugin's folder in the Plugins folder of your project here or if your project is on git, add this command in the Plugins folder of your project:
```
git add submodule https://github.com/CREW-Brussels/CREWAnimationUtilities.git
```
***

# EditBonePosition
EditBonePosition is intended to modify the position of a bone in a skeletal mesh.
We use it to compensate the drift of a Xsens motion tracking system by attaching a more accurate sensor (in terms of absolute position) to the pelvis of the actor.

In this case we only need to correct the x and y coordinates of the pelvis bone.
![EditBonePositionSettings](https://github.com/CREW-Brussels/CREWAnimationUtilities/assets/6745738/b3125724-6183-4dd8-9594-3d33da8e23c7)

After correcting the offset and orientation of the tracker, it's position can be directly applied to the pelvis bone of the skeletal mesh.
![ExempleBluePrint](https://github.com/CREW-Brussels/CREWAnimationUtilities/assets/6745738/6421679b-c993-4ec1-914d-26669ff1b608)

***

## About
<img src="https://github.com/user-attachments/assets/2ffa225b-2966-4f68-8106-3fd403fd6988" alt="CREW-LOGO" width="130"/>  
<img src="https://emil-xr.eu/wp-content/uploads/2022/10/logo_emil-272x300.png)" alt="EMIL-XR-LOGO" width="100"/>

> CREW Animation utilities, a submodule of EXP, is being developed by [CREW](http://crew.brussels) as part of [EMIL](https://emil-xr.eu/), the European Media and Immersion Lab, an Innovation Action funded by the European Union and co-funded by Innovate UK. 

## Funding
<img src="https://emil-xr.eu/wp-content/uploads/2022/10/EN-Funded-by-the-EU-POS-1024x215.png)" alt="EU" height="100"/>

> This project has received funding from the European Union's Horizon Europe Research and Innovation Programme under Grant Agreement No 101070533 EMIL.
