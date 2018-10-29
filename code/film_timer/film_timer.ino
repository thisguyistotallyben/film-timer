#include <LiquidCrystal.h>


// buttons
const int bUp = 7;
const int bDown = 8;
const int bMenu = 9;
const int bStart = 10;

// button states
int sUp = 0;
int sDown = 0;
int sMenu = 0;
int sStart = 0;

// relay triggers
const int rEn = 0;
const int rSL = 1;

// display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// overall state
/*
  0 - menu
  1 - enlarger timer
  2 - print develop timer
  3 - film develop timer
*/
int state = 0;


void setup() {
  // setup pins
  pinMode(bUp, INPUT);
  pinMode(bDown, INPUT);
  pinMode(bMenu, INPUT);
  pinMode(bStart, INPUT);
  pinMode(rEn, OUTPUT);
  pinMode(rSL, OUTPUT);
  
  // set pins to allow no power
  // not sure if this is necessary
  digitalWrite(rEn, LOW);
  digitalWrite(rEn, LOW);

  // start lcd
  lcd.begin(16, 2);
  
  // print open message and wait
  lcd.print("Ben's Photo");
  lcd.setCursor(0, 1);
  lcd.print("Timer Thing v1");
  delay(1000);
  lcd.clear();
}

void loop() {
  // get states
  sUp = digitalRead(bUp);
  sDown = digitalRead(bDown);
  sMenu = digitalRead(bMenu);
  sStart = digitalRead(bStart);

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
    case 1:
      modeEnlarger(bPressed);
      break;
    case 2:
      modePrintTimer(bPressed);
      break;
    case 3:
      modeFilmTimer(bPressed);
      break;
    default:
      lcd.clear();
      lcd.print("Something Happened.");
  }
}

void modeMenu(int bPressed) {}
void modeEnlarger(int bPressed) {}
void modePrintTimer(int bPressed) {}
void modeFilmTimer(int bPressed) {}
