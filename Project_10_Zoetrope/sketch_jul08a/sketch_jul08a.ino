const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;
const int ledPin = A1;
const int ledOutput = 6;

long ledDelay = 0;
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(ledOutput, OUTPUT);
  digitalWrite(enablePin, LOW);

}

void loop() {

  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);//works


  directionSwitchState = digitalRead(directionSwitchPin); //works
  motorSpeed = analogRead(potPin)/4;
  ledDelay = analogRead(ledPin) ppp;
  
  if(millis() % ledDelay == 0){
    digitalWrite(ledOutput,HIGH);    
  } else {
    digitalWrite(ledOutput,LOW);  
  }


  if(onOffSwitchStateSwitchPin != previousOnOffSwitchState){
  	if(onOffSwitchState == HIGH){
  		motorEnabled = !motorEnabled;  	
  	}
  }
  if(directionSwitchState != previousDirectionSwitchState){
  	if(directionSwitchState == HIGH){
  		motorDirection = !motorDirection;
  	}
  }
  
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW); 
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);    
  }
  
  if(motorEnabled == 1){
  	analogWrite(enablePin,motorSpeed);
  } else {
  	analogWrite(enablePin, 0);
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;

}
