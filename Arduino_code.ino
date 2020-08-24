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

}
