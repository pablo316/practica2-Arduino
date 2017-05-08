#include <Wire.h>




int Lectura_Analogica1 = 0;
int Lectura_Analogica2 = 0;

int led = 13; //led Rojo de prueba de conexión

int SensorHumedad1[2] = {0, 0};
int SensorHumedad2[2] = {0, 0};
char inbyte = 0; //Char para leer el led

void setup() {
  // initialise serial communications at 9600 bps:
  Serial.begin(9600);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void loop() {

  Lectura_Analogica1 = analogRead(A0); //Leer el valor del potenciómetro
  //140=no hay agua-90=exceso de humedad
  // Serial.print("A");
  //Serial.println(Lectura_Analogica1);
  SensorHumedad1[1] = map(Lectura_Analogica1, 0, 132, 100, 0);


  Lectura_Analogica2 = analogRead(A1); //Leer el valor del potenciómetro
  //140=no hay agua-90=exceso de humedad
  SensorHumedad2[1]  = map(Lectura_Analogica2, 0, 132, 100, 0);



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
    //Serial.print('#'); //hay que poner # para el comienzo de los datos, así Android sabe que empieza el String de datos
    Serial.print("Humedad vaso 1:");
    Serial.println(SensorHumedad1[1]);
    Serial.print("Humedad vaso 2:");
    Serial.println(SensorHumedad2[1]);
    Serial.println('~'); //con esto damos a conocer la finalización del String de datos

  }

  delay(10);        //agregamos este delay para eliminar tramisiones faltantes
}
