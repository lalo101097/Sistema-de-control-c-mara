//La variable pone la pantalla correcta, junto a sus datos, en la pantalla
void showscreen(int alfa)
{
  //Limpia la pantalla
  lcd.clear();
  //lo envía a posición 0,0
  lcd.home();
  //Se imprime el título de la pantalla
  lcd.print(funciones[alfa]);
  //Si está en modo edición agrega al final de esta línea un asterisco para hacer más obvio el modo edición
  if (setu == true)
  {
    lcd.print("*");
  }
  //Se pone el el cursor al principio de la segunda línea
  lcd.setCursor(0, 1);
  //Se imprimen los datos
  lcd.print(datos[alfa]);
}

void chk()
{
  if (enc == false)
  {
    enc = true;
  }
  else
  {
    enc = false;
  }
}

void looop()
{
  if (enc == true && seg < millis())
  {
    
    switch (screen)
    {
      case 2:
        lcd.clear();
        ilum();
        break;
      case 3:
        lcd.clear();
        ilumac();
        break;
    }
    seg = millis() + 1000;
  }
}
