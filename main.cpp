//****************************************************************************
// Universidad del Valle de Guatemala
// BE3015 - Electrónica Digital 2
// Gunther Dietmar Menzel - 19106
// PROYECTO 2
// Parte del ESP32
//*****************************************************************************

//*****************************************************************************
// Librerías
//*****************************************************************************
#include <Arduino.h>

//*****************************************************************************
// Definición de pines
//*****************************************************************************
//Definición del pin para el sensor de temperatura
#define sensor 25

//*****************************************************************************
// Prototipos de funciones
//*****************************************************************************
void SensorTemperatura(void); 
void guardarinfo(void);

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int temp=0;

//Tiempos de muestra para los colores
long LastTime;
long SampleTime = 250;

long LastTime2;
long SampleTime2 = 250;

long LastTime3;
long SampleTime3 = 250;

String medidad ="";
String guardado= "";
String prueba = "";

bool comunicacion = false;

//*****************************************************************************
// Configuración
//*****************************************************************************
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200); //Configuración serial


  LastTime = millis(); //Medicion del tiempo
  LastTime2 = millis();

}

//*****************************************************************************
// Loop Principal
//*****************************************************************************
void loop(){

  SensorTemperatura();
  //guardarinfo();
}