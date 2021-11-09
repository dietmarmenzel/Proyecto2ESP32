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

//*****************************************************************************
// Funcion para medir temperatura
//*****************************************************************************
void SensorTemperatura(void){
  temp = analogReadMilliVolts(sensor);
  temp = temp / 10;

   Serial2.println(temp);
   prueba= Serial2.readStringUntil('\n');
  
  Serial.println(prueba);
  //Serial.println(temp);

  if (Serial2.available()>0){
    medidad = Serial2.readStringUntil('\n');
    //Comunicación con monitor
    Serial2.print("Temperatura ");
    Serial2.print(medidad);      
    Serial2.print("°");
    Serial2.println();  
    Serial.println(temp); 
  }

}
//*****************************************************************************
// Funcion para guardar la temperatura medida
//*****************************************************************************
void guardarinfo(void){
  guardado =Serial2.readStringUntil('\n');
  if (guardado =="guardar"){
    Serial.println(temp);
  }

}