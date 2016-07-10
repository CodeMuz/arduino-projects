#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
float angle;

void setup() {
  // put your setup code here, to run once:

myServo.attach(9);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

	potVal = analogRead(potPin);
	Serial.print("\n potVal : ");
	Serial.print(potVal);

float voltage = (potVal / 1024.0) * 5.0;

float temp = (voltage - .5) * 100;

	Serial.print("\n temp : ");
	Serial.print(temp);
//
	angle = map(temp, 18 , 23, 0 , 179);
//
	Serial.print(" angle : ");
	Serial.print(angle);
//
	myServo.write(angle);

	delay(500);
	
}
