
void calib()
{
  lcd.clear();
  lcd.home();
  lcd.print("Calibrando");
  motor.setMaxSpeed(1500);
  motor.setSpeed(1500);
  digitalWrite(endi, HIGH);
  delay(100);
  digitalWrite(endi, LOW);
  while (digitalRead(sens) == HIGH)
  {
    motor.runSpeed();
  }
  digitalWrite(endi, HIGH);
  motor.setCurrentPosition(alt * 8000);
  showscreen(screen);
  cal = true;
}

void mov()
{
  motor.setAcceleration(200);
  motor.setMaxSpeed(2500);
  motor.setSpeed(2500);
  lcd.clear();
  lcd.home();
  lcd.print("Moviendo");
  motor.moveTo((datos[1].toDouble()) * 8000);
  digitalWrite(endi, HIGH);
  delay(100);
  digitalWrite(endi, LOW);
  while (motor.distanceToGo() != 0)
  {
    motor.run();
  }
  digitalWrite(endi, HIGH);
  showscreen(screen);
}
