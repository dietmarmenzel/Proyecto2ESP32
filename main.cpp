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
void SensorTemperatura(void); //Funcion para la medicion del sensor de temperatura
void guardarinfo(void); //Funcion para guardar la informacion de la SD

//*****************************************************************************
// Variables Globales
//*****************************************************************************
int temp=0; //Temperatura en enteros

//Tiempos de muestra
long LastTime;
long SampleTime = 250;

long LastTime2;
long SampleTime2 = 250;

long LastTime3;
long SampleTime3 = 250;
//Guardar los datos 
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
  //Variable del sensor
  SensorTemperatura();
  //guardarinfo();
}

//*****************************************************************************
// Funcion para medir temperatura
//*****************************************************************************
//Declarando el valor de temperatura
void SensorTemperatura(void){
  temp = analogReadMilliVolts(sensor);
  temp = temp / 10;

   Serial2.println(temp);
   prueba= Serial2.readStringUntil('\n');
  //Imprimiendo en monitor serie
  Serial.println(prueba);
  //Serial.println(temp);

  if (Serial2.available()>0){
    medidad = Serial2.readStringUntil('\n');
    //Comunicación con la pantalla
    Serial2.print("Temperatura ");
    Serial2.print(medidad);      
    Serial2.print("°C");
    Serial2.println();  
    Serial.println(temp); 
  }

}
//*****************************************************************************
// Funcion para guardar la temperatura medida
//*****************************************************************************
//Declarando que guarde los resultados del sensor
void guardarinfo(void){
  guardado =Serial2.readStringUntil('\n');
  if (guardado =="guardar"){
    Serial.println(temp);
  }
}