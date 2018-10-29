void clearLine(int l) {
  lcd.setCursor(0, l);
  lcd.write("                ");
}

int pressed(int butt) {
  if (digitalRead(butt) == HIGH) return 0;
  else return 1;
}
