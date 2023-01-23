//Se incluyen las librerías de aceleración, estas permiten acelerar los motores PaP para evitar errores en su movimiento
//Su única función es esta
#include <AccelStepper.h>
#include <MultiStepper.h>
//La librería keypad nos permite poner un teclado matricial como entrada de datos
#include <Keypad.h>            // Prog_19_1
//LA librería wire habilita el uso de la comunicación i2c, esta es muy útil para pantallas y controlar más de 100 dispositivos con este protocolo
#include  <Wire.h>
//La librería liquid crystal nos permite manejar la pantalla del sistema utiliando la conección i2c, esto nos ahorra gran cantidad de pines por un poco de dinero extra por el módulo i2c
#include  <LiquidCrystal_I2C.h>

// Constructor de la librería de LCD 16x2
// Aqui se configuran los pines asignados a la pantalla del PCF8574
LiquidCrystal_I2C lcd(0x27, 20, 4);
//Se ingresa la cantidad de filas y columnas del teclado matricial
const byte Filas = 4;          //Cuatro filas
const byte Cols = 4;           //Cuatro columnas
//Se declara los pines de las columnas y las filas
byte Pins_Filas[] = {5, 6, 7, 8};     //Pines Arduino para las filas
byte Pins_Cols[] = { 9, 10, 11, 12};     // Pines Arduino para las columnas
//Se declara los valores de cada posición del teclado matricial
char Teclas [ Filas ][ Cols ] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'.', '0', '#', 'D'}
};
//Se declara como tal la variable del teclado, con esto ya es posible poder escribir con el teclado
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
//Estas son las pantallas que tendrá el sistema
String funciones[] = {"Tiempo", "Distancia", "Intensidad", "Ilum AC"};
//Se almacena los datos de cada uno de los parámetros
String datos[] = {"0.0", "24.7", "100", "0.0"};

//Pines de salida para el paso, la dirección, activar o desactivar el motor y el buzzer respectivamente
const int sens = A0;
const int paso = 2;
const int direc = 4;
const int endi = 13;
const int lux = 3;
//Se declara la variable de las aceleraciones, donde lo primero es que se declara un motor tipo 1, que es un bipolar estándar, para dar el paso y para la dirección
AccelStepper motor(1, paso, direc);

//Variables
//La pantalla que está mostrando actualmente la pantalla
int screen = 0;
//Nos permite saber si está en modo edición o en modo trabajo, true es edición y false es trabajo
bool setu = false;

bool enc = false;

bool cal = false;

const double alt = 24.7;

unsigned long seg = 0;

void setup() {
  // put your setup code here, to run once:

  //Se declara el pin para habilitar o deshabilitar el motor como una salida digital
  pinMode(endi, OUTPUT);
  pinMode(sens, INPUT_PULLUP);
  //SE inicializa la pantalla con sus medidas de pixeles, que son 16x2
  lcd.init();
  lcd.backlight();
  //SE envía el cursor a la ubicación 0,0 en la pantalla
  lcd.home();
  //Se pone el sistema en la pantalla 0, que es la de velocidad
  showscreen(0);
  //Se pone en alto el pin para habilitar o desabilitar el motor, con eso se desactiva el motor
  digitalWrite(endi, HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
  //Detecta el valor de la tecla que sea pulsada, en caso de que lo sea
  char pulsacion = Teclado1.getKey() ;
  //Si se detecta una tecla presionada se entra al if
  pul(pulsacion);
  looop();
}
