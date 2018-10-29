#include <LiquidCrystal.h>


// buttons
const int bUp = 0;
const int bDown = 1;
const int bMenu = 2;
const int bStart = 3;

// button states
int sUp = 0;
int sDown = 0;
int sMenu = 0;
int sStart = 0;

// relay triggers
const int rEn = 0; // enlarger
const int rSL = 1; // safe light

// display
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// overall state
/*
  0 - menu
  1 - enlarger timer
  2 - print develop timer
  3 - film develop timer
*/
int state = 0;
boolean start = true;


void setup() {
  // setup pins
  pinMode(bUp, INPUT_PULLUP);
  //pinMode(bDown, INPUT);
  //pinMode(bMenu, INPUT);
  //pinMode(bStart, INPUT);
  //pinMode(rEn, OUTPUT);
  //pinMode(rSL, OUTPUT);

  // set pins to allow no power
  // not sure if this is necessary
  //digitalWrite(rEn, LOW);
  //digitalWrite(rEn, LOW);
  
  // start lcd
  lcd.begin(16, 2);

  // print open message and wait
  lcd.print("Ben's Photo");
  lcd.setCursor(0, 1);
  lcd.print("Timer Thing v1");
  delay(2000);
  lcd.clear();
}

void loop() {
  // start in menu
  // execute once only
  if (start) {
    start = false;
    modeMenu(-1);
  }
  
  // get states
  sUp = !digitalRead(bUp);
  /*
  sDown = digitalRead(bDown);
  sMenu = digitalRead(bMenu);
  sStart = digitalRead(bStart);
  */
  sDown = LOW;
  sMenu = LOW;
  sStart = LOW;

  if (sUp == HIGH) {
    doSwitch(sUp);
  }
  else if (sDown == HIGH) {
    doSwitch(sDown);
  }
  else if (sMenu == HIGH) {
    doSwitch(sMenu);
  }
  else if (sStart == HIGH) {
    doSwitch(sStart);
  }
}

void doSwitch(int bPressed) {
  switch(state) {
    case 0:
      modeMenu(bPressed);
      break;
    /*
    case 1:
      modeExpose(bPressed);
      break;
    case 2:
      modePrint(bPressed);
      break;
    case 3:
      modeDevelop(bPressed);
      break;
    */
    default:
      lcd.clear();
      lcd.print("You broke it.");
  }
}
