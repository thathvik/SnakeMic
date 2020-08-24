#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2, 3); // RX, TX

#define en1 5
#define in1 8
#define in2 9
#define en2 6
#define in3 10
#define in4 11

int xDir = 55; //Specifies location of the joystick on screen along x axis (additionally used for custom controls)
int yDir = 55; //Specifies location of the joystick on screen along y axis (additionally used for custom controls)
//Initialize variables to specify the motor speed of both the wheels
int motorSpeed1 = 0;
int motorSpeed2 = 0;

//For curve function
int count = 0;
bool toggleFlag = 0;
void setup() {
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600); // Default communication rate of the Bluetooth module
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  void loop() {
  // Read the incoming data from the Smartphone Android App
  while (Bluetooth.available() >= 2) {
    xDir = Bluetooth.read();
    delay(10);
    yDir = Bluetooth.read();
    Serial.print(xDir);
    Serial.print(",");
    Serial.println(yDir);
  }
  delay(10);
  // Makes sure we receive correct values
  //Custom Inputs - Straight, Circle, Sine, Stop, Rotate In Place
  if (xDir == 5)
  {
    switch (yDir)
    {
      case 172: // Go straight
        motorSpeed1 = 250;
        motorSpeed2 = 250;
        forward();
        break;
      case 174: // Circle
        motorSpeed1 = 250;
        motorSpeed2 = 200;
        forward();
        break;
      case 176: // Sine or Wave motion
        if (toggleFlag)
        {
          motorSpeed1 = 250;
          motorSpeed2 = 200;
        }
        else
        {
          motorSpeed1 = 200;
          motorSpeed2 = 250;
        }
        curve();
        break;
      case 178: //Rotate in place
        motorSpeed1 = 250;
        motorSpeed2 = 250;
        turnRight();
        break;
      case 180: //Stop
        Stop();
        break;
    }
  }
  else
  {
    //Joystick Control
    if (xDir > 50 && xDir < 120 && yDir > 50 && yDir < 120) {
      Stop();
    }
    if (yDir > 50 && yDir < 120) {
      if (xDir < 50) {
        turnRight();
        motorSpeed1 = map(xDir, 50, 10, 0, 255);
        motorSpeed2 = map(xDir, 50, 10, 0, 255);
      }
      if (xDir > 120) {
        turnLeft();
        motorSpeed1 = map(xDir, 120, 150, 0, 255);
        motorSpeed2 = map(xDir, 120, 150, 0, 255);
      }
    } 
    else {
      if (xDir > 50 && xDir < 120) {

        if (yDir < 50) {
          forward();
        }
        if (yDir > 120) {
          backward();
        }
        if (yDir < 50) {
          motorSpeed1 = map(yDir, 50, 10, 0, 255);
          motorSpeed2 = map(yDir, 50, 10, 0, 255);
        }
        if (yDir > 120) {
          motorSpeed1 = map(yDir, 120, 150, 0, 255);
          motorSpeed2 = map(yDir, 120, 150, 0, 255);
        }
      } 
      else {
        if (yDir < 50) {
          forward();
        }
        if (yDir > 120) {
          backward();
        }
        if (xDir < 50) {
          motorSpeed1 = map(xDir, 50, 10, 255, 50);
          motorSpeed2 = 255;
        }
        if (xDir > 120) {
          motorSpeed1 = 255;
          motorSpeed2 = map(xDir, 120, 150, 255, 50);
        }
      }
    }
  }
  //Serial.print(motorSpeed1);
  //Serial.print(",");
  //Serial.println(motorSpeed1);

  analogWrite(en1, motorSpeed1); // Send PWM signal to motor A
  analogWrite(en2, motorSpeed2); // Send PWM signal to motor B
}

}
