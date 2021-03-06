#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int yesPin = 6;
const int noPin = 9;

const int seedPin = A0; //use analog read for random seed

int prevNumber = 0; // prevent the same number twice
int yesState = 0;
int noState = 0;

int totalAnswers = 0;
int correctAnswers = 0;

int mutex = 0; //locking device

const int maxNumber = 3167;

const int TOP_ROW = 0;
const int BOTTOM_ROW = 1;

const int second = 1000; // 1 s = 1000 ms

//to do count the number of correct results
//int correct = 0;

boolean isPrime(long n) {

  if (n <= 1) {
    return false;
  } else if (n <= 3 ) {
    return true;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }
  int i = 5;
  while ((i * i) <= n) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
    i = i + 6;
  }
  return true;

}

/*
Returns an odd integer between 0 and maxNumber
*/
long generateNewNumber() {

  long n = random(11 * analogRead(seedPin)) % maxNumber;
  
  //bias distribution to return higher percent composite
  if(n % 2 == 0 || n % 3 == 0 || n == 1 || n == prevNumber){
    return generateNewNumber();  
  }
  
  prevNumber = n;

  return n;
}


void setup() {

  lcd.begin(16, 2);

  pinMode(yesPin, INPUT);
  pinMode(noPin, INPUT);

  lcd.clear();

Serial.begin(9600);

}

void printScore(int yesState, long number){

    lcd.setCursor(0, BOTTOM_ROW);

    //Did user guess correct
    if (yesState == isPrime(number)) {
      correctAnswers = correctAnswers + 1;
    }
    
    totalAnswers = totalAnswers + 1;

    lcd.setCursor(0, BOTTOM_ROW);
    lcd.print("Score: " + String(correctAnswers) + " / " + String(totalAnswers));
}

long printNewNumber(){

    long number = generateNewNumber();
    lcd.setCursor(0, TOP_ROW);
    lcd.print(number);

    return number;
}

void loop() {

  static long number;

  //Generate a new number
  if (number == NULL)
  {
    number = printNewNumber();    
  }

  yesState = digitalRead(yesPin);
  noState = digitalRead(noPin);

  if ((yesState == HIGH || noState == HIGH) && mutex == 0) {

    mutex = 1;

    //Reset LCD screen prior to next number
    lcd.clear();

    printScore(yesState, number);

    number = printNewNumber();

    delay(1 * second); //prevent switch overload

    mutex = 0;
  
  }
}
