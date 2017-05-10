#include <Wire.h>

int Lectura_Analogica1 = 0;
int Lectura_Analogica2 = 0;

//pines digitales que utilizaremos para energizar los sensores de humedad de suelo.
int vcc1 = 8;
int vcc2 = 9;

//vectores para almacenar la informacion obtenida por los sensores , la info se guarda para cada vector el la posicion 1 , la posicion 0 es para solicitar el envio de ese dato .
int SensorHumedad1[2] = {0, 0};
int SensorHumedad2[2] = {0, 0};
char inbyte = 0; //Char para leer el led.

void setup() {
  Serial.begin(9600);
  //realiza el envio de energia (5v) a los sensores de humedad de suelo para comenzar con las lecturas .
  digitalWrite(vcc1, HIGH);
  digitalWrite(vcc2, HIGH);
}

void loop() {

  //funcion map tiene como parametro la lectura analogica del sensor , max voltage recibido por el sensor , min voltage recibido por el sensor , los valores siguientes son una representacion entre cero y cien de la cantidad de voltage recidido para su representacion en porcentaje.
  Lectura_Analogica1 = analogRead(A0); //Leer el valor del potenciómetro(sensor de humedad de suelo).
  if (Lectura_Analogica1 < 0){ //aseguramos que no guarde valores negativos ya que son datos basura generados por el sensor.
    Lectura_Analogica1 = 0;
  }
  SensorHumedad1[1] = map(Lectura_Analogica1, 0, 132, 100, 0);


  //funcion map tiene como parametro la lectura analogica del sensor , max voltage recibido por el sensor , min voltage recibido por el sensor , los valores siguientes son una representacion entre cero y cien de la cantidad de voltage recidido para su representacion en porcentaje.
  Lectura_Analogica2 = analogRead(A1); //Leer el valor del potenciómetro(sensor de humedad de suelo).
  if (Lectura_Analogica1 < 0){ //aseguramos que no guarde valores negativos ya que son datos basura generados por el sensor.
    Lectura_Analogica1 = 0;
  }
  SensorHumedad2[1]  = map(Lectura_Analogica2, 0, 132, 100, 0);


  //preguntar si hay un serial(bluetooth) conectado .
  if (Serial.available() > 0) {
    inbyte = Serial.read();
    //preguntar si el serial(bluetooth) esta solicitando el envio de datos.
    if (inbyte == '2')//pidiendo datos
    {
      SensorHumedad1[0] = 1;
      SensorHumedad2[0] = 1;
    }
  }
  //llama funcion de envio de datos.
  sendAndroidValues();
  delay(2000);
}


//enviar los valores  por el modulo Bluetooth a Android.
void sendAndroidValues() {

  if (SensorHumedad1[0] == 1 || SensorHumedad2[0] == 1) {
    Serial.println(' '); //con esto damos a conocer la finalización del String de datos.
  }

  if (SensorHumedad1[0] == 1) {
    Serial.print("Humedad vaso 1:");
    Serial.println(SensorHumedad1[1]);
  }

  if (SensorHumedad2[0] == 1) {
    Serial.print("Humedad vaso 2:");
    Serial.println(SensorHumedad2[1]);

  }
  if (SensorHumedad1[0] == 1 || SensorHumedad2[0] == 1) {
    Serial.print('~'); //con esto damos a conocer la finalización del String de datos.
  }
  delay(10);        //agregamos este delay para eliminar tramisiones faltantes.
}
