void set()
{
  //Se pone un subciclo para la edición, esto nos ayuda para tener diferentes usos de las teclas y no tener que enredarnos con más condiciones y ciclos
  while (setu == true)
  {
    //Detecta el valor de la tecla que sea pulsada, en caso de que lo sea
    char pulsacion = Teclado1.getKey();
    //Si no se presiona tecla no pasa nada, si se presiona entra a este ciclo
    if (pulsacion != 0)
    {
      //Se usa una sentencia switch-case para realizar la acción para la tecla presionada
      switch (pulsacion)
      {
        case 'A':
          //Si se presiona A se borra un caracter, esto sólo se efectúa si hay algo en el string, si está vacío no se realiza acción alguna
          if (datos[screen] != "")
          {
            //Se saca la longitud del string
            int len = datos[screen].length();
            //Se elimina el último caracter, esto poque sólo se conserva la longitud total menos 1
            datos[screen].remove(len - 1);
          }
          break;
        case 'B':
          //Se mueve a la izquierda en el menú de pantallas excepto si está en la pantalla más a la izquierda
          if (screen != 0)
          {
            //Se reduce en uno el valor de la pantalla actual, esto mueve al a izquierda en el menú
            screen--;
          }
          break;
        case 'C':
          //Lo mismo que la anterior sólo que se mueve ala derecha y termina en la pantalla más a la derecha
          if (screen != 3)
          {
            //Aumenta en uno el valor de la pantalla actual
            screen++;
          }
          break;
        case 'D':
          //Saca del modo edición
          setu = false;
          //Le da una pausa al programa para evitar errores
          delay(500);
          break;
        //De aquí en adelante inserta el caracter que tenga en cada posición, para esto usa concatenación, que es poner el valor anterior y le agrega el valor de la tecla usando un signo más, y lo guarda en la
        //misma variable
        case '1':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '2':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '3':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '4':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '5':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '6':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '7':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '8':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '9':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '0':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
        case '.':
          datos[screen] = datos[screen] + String(pulsacion);
          break;
      }
      //Se carga toda la pantalla
      showscreen(screen);
    }
  }
}
