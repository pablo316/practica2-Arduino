#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //myservo.attach(9); // Asocia la variable al pin donde está conectado el servo.
  //delay(5000);
        char dato = Serial.read();
        if(dato == 'w'){
            myservo.attach(9);
          Serial.println("avanza a velocidad 120");
          myservo.write(120); // Gira lentamente en una dirección durante 4 segundos.
          
        }

        if(dato =='s'){
          myservo.attach(9);
          Serial.println("retrocede a velocidad 60");
          myservo.write(60); // Gira lentamente en una dirección durante 4 segundos.
          }
        if(dato =='c'){
           myservo.detach();
          Serial.println("detener");
        }
        if(dato =='d'){
          myservo.attach(9);
          Serial.println("envio d");
          myservo.write(120); // Gira lentamente en una dirección durante 4 segundos.
          delay(3000);
          myservo.detach();
          Serial.println("detener");
        }
        if(dato =='e'){
          myservo.attach(9);
          Serial.println("envio e");
          myservo.write(98); // Gira lentamente en una dirección durante 4 segundos.
          delay(3000);
          myservo.detach();
          Serial.println("detener");
        }
  //delay(5000);
 //myservo.detach(); // Desasocia la variable Servo de su pin

  
}
