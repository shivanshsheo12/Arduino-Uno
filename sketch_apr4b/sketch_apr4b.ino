/*
 * Bronze ELC Project - To pick an object from source and drop at right angle from the source location.
   Made by -  Aayushman Tomar, Ritwik Gupta, Daksh, Arushi, Mishika, Sukhmann

   mtr is the shortform of motor
   

*/

#include <AFMotor.h>
AF_DCMotor mtr1(1); //claw
AF_DCMotor mtr2(2); // rotate
AF_DCMotor mtr3(3); // up-down
AF_DCMotor mtr4(4); // forward backward



void setup() {
  Serial.begin(9600); // Initializing Baud Rate
  mtr1.setSpeed(150);
  mtr1.run(RELEASE);
  mtr2.setSpeed(3000);
  mtr2.run(RELEASE);
  mtr3.setSpeed(500);
  mtr3.run(RELEASE);
  mtr4.setSpeed(500);
  mtr4.run(RELEASE);
}

void loop() {
  down();
  delay(150);
  claw();
  delay(150);
  up();
  delay(150);
  rotate_90();
  delay(150);
  down();
  delay(150);
  claw();
  delay(150);
  up();
  delay(150);
}

void claw()
{
  Serial.println("Claw is Opening");
  mtr1.run(FORWARD);      // turn it on going forward
  delay(1000);
  Serial.println("Claw is Closing");
  mtr1.run(BACKWARD);     // the other way
  delay(2500);
}

void rotate_90() {
  Serial.println("Rotating");
  mtr2.run(FORWARD);
  delay(570);
  mtr2.run(RELEASE);
  delay(6000);

}

void up() {
  Serial.println("Arm is going Up");
  mtr4.run(FORWARD);
  delay(500);
  mtr4.run(RELEASE);
}

void down() {
  mtr4.run(BACKWARD);
  delay(500);
  mtr4.run(RELEASE);
}