#include <Wire.h>

float Humedad = 0;


int Lectura_Analogica = 0;


int led = 13; //led Rojo de prueba de conexión

float SensorHumedad1[2] = {0, 0};
char inbyte = 0; //Char para leer el led

void setup() {
  // initialise serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  digitalWrite(8, HIGH);
}

void loop() {

  Lectura_Analogica = analogRead(A0); //Leer el valor del potenciómetro
  //140=no hay agua-90=exceso de humedad
  float Humedad = map(Lectura_Analogica, 90, 140,100, 0);
  

  SensorHumedad1[1] = Humedad;
  


  if (Serial.available() > 0) {

    inbyte = Serial.read();
    
    if (inbyte == '2')//pidiendo datos
    {
      SensorHumedad1[0] = 1;
    
    }
    if (inbyte == '1')
    {
      SensorHumedad1[0] = 0; 
    }
  }

  sendAndroidValues();
  delay(2000);
}


//enviar los valores por el dipositivo android por el modulo Bluetooth
void sendAndroidValues()
{
  if (SensorHumedad1[0] == 1) {
    Serial.print('#'); //hay que poner # para el comienzo de los datos, así Android sabe que empieza el String de datos
    Serial.print("Humedad vaso 1:");
    Serial.print(SensorHumedad1[1]);
    Serial.print('~'); //con esto damos a conocer la finalización del String de datos
    Serial.println();
  }

  delay(10);        //agregamos este delay para eliminar tramisiones faltantes
}
