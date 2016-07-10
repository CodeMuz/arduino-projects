const int switchPin = 2;
const int motorPin = 9;

int switchState = 0;

void setup() {

  Serial.begin(9600);
  
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:

  switchState = digitalRead(switchPin);
  
  Serial.print(switchState);
    
  if(switchState  == HIGH){
   digitalWrite(motorPin,HIGH);
  } else {
   digitalWrite(motorPin,LOW);
  }
}
