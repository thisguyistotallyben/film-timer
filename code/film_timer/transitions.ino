void arrowTransition() {
  lcd.setCursor(0, 1);
  for (int i = 0; i < 16; i++) {
    lcd.print(">");
    delay(15);
  }
}

void tWipeOut() {
  for (int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.print(" ");
    lcd.setCursor(i, 1);
    lcd.print(" ");
    delay(20);
  }
}
