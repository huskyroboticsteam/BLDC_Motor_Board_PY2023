# Hindsight CAN Drivers
## Use these drivers for Embedded CAN Communications on Hindsight (PY2020) Rover.

### More information
For more information on the protocol standard, please visit the Slite documentation HUB for Husky Robotics. The protocol documentation is under the Electronics/CAN/CAN Protocol sheet.<br />

## Implementation information

### How To Use
_Note: You will need to have the standard C libraries compiled with your code. This is usually done automatically. If you have problems with `stdint.h` let Jaden know._<br /><br />
<ins>*STEP 1*</ins><br />
Within your repository for your firmware create a submodule with this repo in it. You can follow [this guide](https://git-scm.com/book/en/v2/Git-Tools-Submodules) for instructions on how to do that and explanations for what exactly a submodule is.<br />
Usually this command is done as follows: <br />
```git submodule add git@github.com:huskyroboticsteam/HindsightCAN.git path_to_your_source```<br />
And then:<br />
```git submodule init```<br />
If you **put these files in the same folder as your source code**, you can skip the next step.<br />

<ins>*STEP 2*</ins><br />
Add all of the source files to your compiler path within whatever IDE you are using. This will be dependent on what IDE you are using and how you are building your code. Since most people here will not be using a Makefile, we cannot give explicit direction on how to do this. If you have trouble, talk to Jaden, Dylan, or someone else who has done it. Please try Googling it and figuring it out yourself first though.<br /><br />
<ins>*STEP 3*</ins><br />
Import all of the relevant headers into your project. All devices will need to import `CANCommon.h`, which gives you access to the files that are necessary for interpretting and creating Common Mode packets. But if you are working on a Motor Unit for example, you will need to also import `CANMotorUnit.h` to give you access to the functions pertinent to specifically a motor unit. If you are writing software for the Jetson, you will need to import all of them! Yay! /s<br /><br />
<ins>*STEP 4*</ins><br />
You have to implement all of the hardware functionality for physically sending and receiving packets. In this repo, you will find a `Port.h` file. Please create a C-code file called `Port[DeviceName].c`, in that file `#include "Port.h"` and implement all of the functions in that header. Right now these CAN Drivers do not actually call those functions, so arbitrating when to send and receive is up to you as the firmware developer, so you will have to manually call those functions. This header is just to get you started and to make sure everyone is on the same page.

### How to Update This Library in Your Project
To update your submodule call: ```git submodule update```, this should pull the changes from the master branch of this repo so you can get updates when we fix our broken code.

### How to Port to a New Chip
This library was built to be portable to any microcontroller or processor. To port it:
1.) Create Port[chipname].c file in a folder of port files (you can copy the PortTemplate.c file to get started)
2.) Add #if CHIP_TYPE == CHIP_TYPE_xxx to top of C file, #endif at the bottom
3.) Add CHIP_TYPE_xxx to the list of defined chips in port.h, with an incremented value.
4.) Implement functs whose prototypes are in port.h
5.) Compile, passing in constant to gcc using -D CHIP_TYPE=CHIP_TYPE_xxx .

Using this method, there should only be one implementation of these port functions visible to the complier after the preprocessor has run.
