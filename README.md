# SnakeMic
This a project done as a part of the master's course Advanced Mechatronics (ME-GY - 6933) in NYU-Tandon, taken by Professor Vikram Kapila. This project was mentored and envisioned by Art visionary Professor Alejandro Moreno Jashes from NYU-Tish.

# Abstract
To alleviate a theatrical experience, a mic that can crawl around like a snake and speak when intended was created. In order to maintain the quality of the sound, a Bose SoundLink Micro Speaker was fitted into a mic-shaped chassis. With the help of an Arduino and a Bluetooth module, this Snake-Mic can be controlled using a user friendly Android App that was developed.

## Requirments
### Hardware
* Arduino (Nano recomended for size)
* 2x DC Motors
* Caster Wheel
* Bose Sounlink Micro / Other small speakers
* 3D Model of the mic (checkout files Iter_1, Iter_2, and [Iter_3](https://github.com/thathvik/SnakeMic/tree/master/Iter_3) to choose the desired 3D model to 3D print)
* HC-05/HC-06 
* Andriod Phone with a Bluetooth

### Software
* Ardunio IDE
* Qura for 3D print
* Andriod App (apk provided)

## Description 
This is a mobile robot shaped like a mic, with a speaker embeded inside. With the principle of Differential drive, this Robot consists of 2 DC motors for movement and is controlled by the Ardunio Nano, with the Arduino code. The Bluetooth Speaker can be operated seperately for any desired sound effect. The assembly is explained in detail in the [Report](https://github.com/thathvik/SnakeMic/blob/master/Project_Report.pdf).

Using the given .apk file, install the app on an Andriod device. Then, connect the HC-05/06 module to the android device and open the app to opperate the mobile robot.
