const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

const int high = 255;

void setup() {

	Serial.begin(9600);

	pinMode(greenLEDPin,OUTPUT);
	pinMode(redLEDPin,OUTPUT);
	pinMode(blueLEDPin,OUTPUT);

}

void loop() {
	
//	analogWrite(redLEDPin,high);
//	delay(1000);
//        analogWrite(redLEDPin,0);
//                
//	analogWrite(greenLEDPin,high);
//	delay(1000);
//	analogWrite(greenLEDPin,0);
//	analogWrite(blueLEDPin,high);
//	delay(1000);
//	analogWrite(blueLEDPin,0);


int pin1 = random(3);
int pin2 = random(3);

analogWrite(greenLEDPin,0);
analogWrite(redLEDPin,0);
analogWrite(blueLEDPin,0);

if(pin1 == 1){ 
  analogWrite(blueLEDPin,random(high));
} else if(pin1 == 2){ 
  analogWrite(greenLEDPin,random(high));  
} else {  
  analogWrite(redLEDPin,random(high));
}

if(pin2 == 1){ 
  analogWrite(blueLEDPin,random(high));
} else if(pin2 == 2){ 
  analogWrite(greenLEDPin,random(high));  
} else {  
  analogWrite(redLEDPin,random(high));
}

delay(1000);
	// for(redValue = 0;redValue < high;redValue++){
	// 	for(greenValue = 0;greenValue < 60;greenValue++){
	// 		for(blueValue = 0;blueValue < 6;blueValue++){
	// 			analogWrite(redLEDPin,redValue);
	// 			analogWrite(greenLEDPin,greenValue * 5);
	// 			analogWrite(blueLEDPin,blueValue * 50);
	// 			delay(50);
	// 		}
	// 	}
	// }	

}
