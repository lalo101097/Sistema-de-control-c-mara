void pul(char pulsacion)
{
  if (pulsacion != 0)
  {
    //Se usa el switch-case como en el caso anterior
    switch (pulsacion)
    {
      //TOdas las sentencias son iguales que las anteriores con la punica diferencia de D
      case 'B':
        if (screen != 0 && enc == false)
        {
          screen--;
          //Se tiene que recargar la pantalla luego de cada movimiento
          showscreen(screen);
        }
        break;
      case 'C':
        if (screen != 3 && enc == false)
        {
          screen++;
          showscreen(screen);
        }
        break;
      case 'D':
        if (enc == false)
        {
          //Se activa el modo de edición
          setu = true;
          //Se recarga la pantalla en modo edicióm
          showscreen(screen);
          //se entra a la función edición
          set();
        }
        break;
      //Este modo sólo es accesible en modo de trabajo
      case '#':
        switch (screen)
        {
          case 0:
            if ((datos[2].toInt()) != 0)
            {
              chk();
              ilum();
            }
            else
            {
              lcd.clear();
              lcd.home();
              lcd.print("Intensidad 0");
              delay(1000);
              showscreen(screen);
            }
            break;
          case 1:
            if (cal == true)
            {
              if (datos[1].toDouble() > alt)
              {
                lcd.clear();
                lcd.home();
                lcd.print("Demasiado alto");
                lcd.setCursor(0, 1);
                lcd.print("Use altura menor");
                delay(2000);
                showscreen(screen);
              }
              else if (datos[1].toDouble() < 3)
              {
                lcd.clear();
                lcd.home();
                lcd.print("Demasiado bajo");
                lcd.setCursor(0, 1);
                lcd.print("Use altura mayor");
                delay(2000);
                showscreen(screen);
              }
              else
              {
                mov();
              }
            }
            else
            {
              calib();
            }
            break;
          case 2:
            if ((datos[2].toInt()) != 0)
            {
              chk();
              ilum();
            }
            else
            {
              lcd.clear();
              lcd.home();
              lcd.print("Intensidad 0");
              delay(1000);
              showscreen(screen);
            }
            break;
          case 3:
            pulsacion = ' ';
            chk();
            ilumac();

            break;
        }

        break;
    }
  }
}
