void ilum()
{
  int td = datos[0].toInt();
  if (td == 0 && datos[2].toInt() <= 100)
  {
    analogWrite(lux, map(datos[2].toInt(), 0, 100, 0, 255));
    lcd.home();
    lcd.print("Trabajando");
    lcd.setCursor(0, 1);
    lcd.print("Intensidad: ");
    lcd.print(datos[2]);
    lcd.setCursor(0,2);

    
    if (enc == false)
    {
      analogWrite(lux, 0);
      showscreen(screen);
    }
  }
  else if (datos[2].toInt() <= 100)
  {
    unsigned long t1 = 0;
    analogWrite(lux, map(datos[2].toInt(), 0, 100, 0, 255));
    enc = true;
    lcd.clear();
    t1 = millis() + ((unsigned long)datos[0].toInt() * 1000);

    while (floor((t1 - millis()) / 1000) != 0)
    {
      lcd.home();
      lcd.print("Trabajando");
      lcd.setCursor(0, 1);
      lcd.print("Intensidad: ");
      lcd.print(datos[2]);
      lcd.setCursor(0, 2);
      lcd.print("Restante: ");
      lcd.print(floor((t1 - millis()) / 1000));
      char pulsacion = Teclado1.getKey() ;
      if (pulsacion == '#')
      {
        break;
      }
    }
    analogWrite(lux, 0);
    showscreen(screen);
    enc = false;
  }
  else
  {
    lcd.clear();
    lcd.home();
    lcd.print("Intensidad alta");
    showscreen(screen);
  }
}

void ilumac()
{
  int td = datos[0].toInt();
  if (td == 0)
  {
    digitalWrite(A1, LOW);
    lcd.home();
    lcd.print("Trabajando");
    if (enc == false)
    {
      digitalWrite(A1, HIGH);
      showscreen(screen);
    }
  }
  else
  {
    unsigned long t1 = 0;
    digitalWrite(A1, LOW);
    enc = true;
    lcd.clear();
    t1 = millis() + ((unsigned long)td * 1000);

    while (millis() < t1)
    {
      lcd.home();
      lcd.print("Trabajando");
      lcd.setCursor(0, 1);
      lcd.print("Intensidad: ");
      lcd.print(datos[2]);
      lcd.setCursor(0, 2);
      lcd.print("Restante: ");
      lcd.print(floor((t1 - millis()) / 1000));
      char pulsacion = Teclado1.getKey() ;
      if (pulsacion == '#')
      {
        break;
      }
    }
    digitalWrite(A1, HIGH);
    showscreen(screen);
    enc = false;
  }
}
