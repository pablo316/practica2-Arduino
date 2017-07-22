#include <DHT11.h>
#include <Wire.h>

// sensores que vamos a utilizar(3 sensores de humedad de suelo + 1 sensor de temperatura y humedad ambiente)
int Lectura_Analogica1 = 0;
int Lectura_Analogica2 = 0;
int Lectura_Analogica3 = 0;
int pin=12;
DHT11 dht11(pin);

//pines digitales que utilizaremos para energizar los sensores de humedad de suelo.
int vcc1 = 10;
int vcc2 = 6;
int vcc3= 4;

//vectores para almacenar la informacion obtenida por los sensores , la info se guarda para cada vector el la posicion 1 , la posicion 0 es para solicitar el envio de ese dato .
int SensorHumedad1[2] = {0, 0};
int SensorHumedad2[2] = {0, 0};
int SensorHumedad3[2] = {0, 0};
char inbyte = 0; //leer el dato recibido desde el monitor serial o bluetooth.

void setup() {
  Serial.begin(9600);
  //realiza el envio de energia (5v) a los sensores de humedad de suelo para comenzar con las lecturas .
  digitalWrite(vcc1, HIGH);
  digitalWrite(vcc2, HIGH);
  digitalWrite(vcc3, HIGH);
  Serial.println("Sensores Energizados");//mensaje por monitor para indicar que se inicio correctamente
}

void loop() {

  //funcion map tiene como parametro la lectura analogica del sensor , max voltage recibido por el sensor , min voltage recibido por el sensor , los valores siguientes son una representacion entre cero y cien de la cantidad de voltage recidido para su representacion en porcentaje.
  Lectura_Analogica1 = analogRead(A0); //Leer el valor del potenciómetro(sensor de humedad de suelo).
 if (Lectura_Analogica1 > 132){ //aseguramos que no guarde valores negativos ya que son datos basura generados por el sensor.
   Lectura_Analogica1 = 132;
   }
  SensorHumedad1[1] = map(Lectura_Analogica1,  0 , 132, 100, 0);


  //funcion map tiene como parametro la lectura analogica del sensor , max voltage recibido por el sensor , min voltage recibido por el sensor , los valores siguientes son una representacion entre cero y cien de la cantidad de voltage recidido para su representacion en porcentaje.
  Lectura_Analogica2 = analogRead(A1); //Leer el valor del potenciómetro(sensor de humedad de suelo).
 if (Lectura_Analogica2 > 132){ //aseguramos que no guarde valores negativos ya que son datos basura generados por el sensor.
   Lectura_Analogica2 = 132;
 }
  SensorHumedad2[1]  = map(Lectura_Analogica2, 0, 132, 100, 0);


Lectura_Analogica3 = analogRead(A4); //Leer el valor del potenciómetro(sensor de humedad de suelo).
 if (Lectura_Analogica1 > 132){ //aseguramos que no guarde valores negativos ya que son datos basura generados por el sensor.
   Lectura_Analogica1 = 132;
   }
  SensorHumedad3[1] = map(Lectura_Analogica3,  0 , 132, 100, 0);

  //preguntar si hay un serial(bluetooth) conectado .
  if (Serial.available() > 0) {
    inbyte = Serial.read();
    //preguntar si el serial(bluetooth o monitor) esta solicitando el envio de datos.
    if (inbyte == '2')//pidiendo datos
    {
      SensorHumedad1[0] = 1;
      SensorHumedad2[0] = 1;
      SensorHumedad3[0] = 1;
    }
  }

  
  //llama funcion de envio de datos.
  sendAndroidValues();
  delay(3000);// mientras "inbyte" sea 2 se actualizaran los valores de las lecturas cada 3 seg, 
}


//enviar los valores  por el modulo Bluetooth o por monitor.
void sendAndroidValues() {

  if (SensorHumedad1[0] == 1 || SensorHumedad2[0] == 1|| SensorHumedad3[0] == 1 ) {
    Serial.println(' '); //con esto damos a conocer el inicio del String de datos.
  }

  if (SensorHumedad1[0] == 1) {
    Serial.print("Humedad vaso 1:");
    Serial.println(SensorHumedad1[1]);
  }

  if (SensorHumedad2[0] == 1) {
    Serial.print("Humedad vaso 2:");
    Serial.println(SensorHumedad2[1]);

  }
  if (SensorHumedad3[0] == 1) {
    Serial.print("Humedad vaso 3:");
    Serial.println(SensorHumedad3[1]);

  }
  //calculamos la humedad y temperatura del ambiente DTH11
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0&&(SensorHumedad1[0] == 1 || SensorHumedad2[0] == 1|| SensorHumedad3[0] == 1 ))
  {
    //enviamos los datos a traves del Serial
    Serial.print("Temperatura:");
    Serial.print(temp);
    Serial.print(" Humedad:");
    Serial.print(humi);
    Serial.println();
  }
 

  
  if (SensorHumedad1[0] == 1 || SensorHumedad2[0] == 1|| SensorHumedad3[0] == 1) {
    Serial.print('~'); //con esto damos a conocer la finalización del String de datos.
  }
  delay(10);        
}
