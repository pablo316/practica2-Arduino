#include <Wire.h>
#include <DHT11.h>
int pin=9;
DHT11 dht11(pin); 
int Humedad=0;
int Lectura_Analogica=0; 
void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
}

void loop() {
        Lectura_Analogica= analogRead(A0); //Leer el valor del potenciómetro 
        float Humedad = map(Lectura_Analogica, 0, 1023, 1024, 0); 
        float Porcentaje= Humedad/10.24;

        Serial.println();
        Serial.print("Humedad de suelo: ");
        Serial.print(Humedad);
        Serial.print(" Porcentaje: ");
        Serial.print(Porcentaje);
        Serial.print("%");
        Serial.println();
         int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
        delay(2000);

}
