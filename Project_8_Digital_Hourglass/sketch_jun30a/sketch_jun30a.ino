const int switchPin = 8;

int direction = 1;

unsigned long previousTime = 0;

int switchState = LOW;
int prevSwitchState = 0;

int led = 2;

void setup() {
  // put your setup code here, to run once:
  
  for(int x = 2;x < 8; x++){
   pinMode(x, OUTPUT) ;
  }
  pinMode(switchPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentTime = millis();
  
  if(led == switchPin){
   resetLights(currentTime);

  }
  
  if(currentTime - previousTime > random(5000)){
    previousTime = currentTime;
    if(direction == 1){
       digitalWrite(9 - led, HIGH);
    } else {
         digitalWrite(led, HIGH);      
    }

   led++;    
  }
  
  switchState = digitalRead(switchPin);
  
  Serial.println(switchState);
  Serial.println("led :");
  Serial.println(led);
  Serial.print("\n");
  
  if(switchState != prevSwitchState){
   resetLights(currentTime);
  }
  
  prevSwitchState = switchState;
  
}

void resetLights(unsigned long currentTime){
  for(int x = 3; x < 7; x++) {
    digitalWrite(x, LOW);
   }
   
   led = 2;
   previousTime = currentTime;
   
   direction = 0 - direction;
   
}
