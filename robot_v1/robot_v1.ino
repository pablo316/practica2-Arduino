
#include <Servo.h>
#include <Wire.h>

Servo izq;  // create servo object to control a servo
Servo der;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

char incoming = '0';   // for incoming serial data



void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object //
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incoming = Serial.read();

    // say what you got:
   // Serial.print("dato recibido: ");
    //Serial.println(incoming);


    //ingresar 2 motor retrocede
    if (incoming == '2') {
      izq.attach(11);
      der.attach(12);
      izq.write(180);
      der.write(0);
      
      
      
    }

    if (incoming == '1') {
      izq.attach(11);
      der.attach(12);
      izq.write(0);
      der.write(180);
     
    }

    if (incoming == '3') {
      izq.attach(11);
      der.attach(12);
      izq.write(0);
      der.write(0);
     
    }

    if (incoming == '4') {
      izq.attach(11);
      der.attach(12);
      izq.write(180);
      der.write(180);
     
    }


    if (incoming == '5') {
      izq.attach(11);
      der.attach(12);
      izq.write(180);
      der.write(45);
      
    }

    if (incoming == '6') {
      izq.attach(11);
      der.attach(12);
      izq.write(180);
      der.write(50);
      
    }

    if (incoming == '0') {
      der.detach();
      izq.detach();

    }
    
  }
 
}
