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
const int rEn = 4; // enlarger
const int rSL = 5; // safe light

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
  delay(1500);
  tWipeOut();
}

void loop() {
  // start in menu
  // execute once only
  if (start) {
    start = false;
    modeMenu(-1);
    return;
  }


  if (pressed(bUp)) {
    doSwitch(sUp);
    delay(400);
  }
  else if (pressed(bDown)) {
    doSwitch(sDown);
    delay(400);
  }
  /*
  else if (pressed(bMenu)) {
    doSwitch(sMenu);
    delay(50);
  }
  */
  if (!pressed(bStart)) {
    //lcd.setCursor(0,0);
    //lcd.print(state++);
    doSwitch(sStart);
    delay(400);
  }
}

void doSwitch(int bPressed) {
  switch(state) {
    case 0:
      modeMenu(bPressed);
      break;
    case 1:
      modeExpose(bPressed);
      break;
    /*
    case 2:
      modePrint(bPressed);
      break;
    */
    case 3:
      modeDevelop(bPressed);
      break;
    default:
      lcd.clear();
      lcd.print("You broke it.");
  }
}
