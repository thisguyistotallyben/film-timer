// variables
int menuCurr = 0;

String options[] = {"Expose", "Print", "Develop"};


void modeMenu(int bPressed) {
    // always do this part
    lcd.clear();
    lcd.print("Menu ( /3)");

    // move through menu
    if (bPressed == bUp) {
      menuCurr = (menuCurr + 1)%3;
    }
    else if (bPressed == bDown) {
      menuCurr = (menuCurr - 1)%3;
    }
    
    // print current menu option
    lcd.setCursor(6, 0);
    lcd.print(menuCurr);
    lcd.setCursor(0, 1);
    lcd.print(options[menuCurr]);
    
    // select
    if (bPressed == bStart) {
      state = menuCurr + 1;
    }
}
