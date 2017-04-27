#include <Wire.h>

int Humedad = 0;
float Porcentaje = 0;
int Lectura_Analogica = 0;


int led = 13; //led Rojo de prueba de conexión

float SensorHumedad1[3] = {0, 0, 0};
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
  float Humedad = map(Lectura_Analogica, 0, 1023, 1024, 0);
  float Porcentaje = Humedad / 10.24;

  SensorHumedad1[1] = Humedad;
  SensorHumedad1[2] = Porcentaje;
  //when serial values have been received this will be true

  if (Serial.available() > 0) {

    inbyte = Serial.read();
    Serial.println(inbyte);
    if (inbyte == '2')//pidiendo datos
    {
      digitalWrite(led, HIGH);
      SensorHumedad1[0] = 1;

    }
    if (inbyte == '1')
    {
      SensorHumedad1[0] = 0;
      digitalWrite(led, LOW);
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
    Serial.print("Humedad:");
    Serial.print(SensorHumedad1[1]);
    Serial.print("Porcentaje:");
    Serial.print(SensorHumedad1[2]);
    Serial.print('~'); //con esto damos a conocer la finalización del String de datos
    Serial.println();
  }

  delay(10);        //agregamos este delay para eliminar tramisiones faltantes
}
