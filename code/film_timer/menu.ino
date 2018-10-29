// variables
int menuCurr = 0;

String options[] = {"Expose", "Print", "Develop"};


void modeMenu(int bPressed) {
  // -1 means just entered menu
  if (bPressed == -1) {
    lcd.clear();
    lcd.print("Menu       ( /3)");
  }
  // move through menu
  else if (bPressed == bUp) {
    menuCurr = (menuCurr + 1)%3;
  }
  else if (bPressed == bDown) {
    menuCurr = (menuCurr - 1)%3;
  }
  
  // print current menu option
  clearLine(1);
  lcd.setCursor(12, 0);
  lcd.print(menuCurr + 1);
  lcd.setCursor(0, 1);
  lcd.print("> " + options[menuCurr]);
  
  /*
  menuCurr++;
  clearLine(1);
  
  delay(1000);
  lcd.setCursor(6, 0);
  lcd.print(menuCurr + 1);
  lcd.setCursor(0, 1);
  lcd.print(options[menuCurr]);
  
  
  
  // select
  if (bPressed == bStart) {
    state = menuCurr + 1;
  }
  */
}
