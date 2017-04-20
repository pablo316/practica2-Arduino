
#include <Servo.h>

Servo izq;  // create servo object to control a servo
Servo der;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int incoming = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  //myservo.attach(9);  // attaches the servo on pin 9 to the servo object //
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incoming = Serial.parseInt();

    // say what you got:
    Serial.print("dato recibido: ");
    Serial.println(incoming);


//ingresar 2 motor retrocede
if(incoming==2){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(0);
delay(2000);
Serial.println("avanzar: ");
incoming=0;
}

if(incoming==1){
izq.attach(9); 
der.attach(8);
izq.write(0);
der.write(180);
delay(2000);
Serial.println("retrocedio: ");
incoming=0;
}

if(incoming==3){
izq.attach(9); 
der.attach(8);
izq.write(0);
der.write(0);
delay(2000);
Serial.println("giro derecha: ");
incoming=0;
}

if(incoming==4){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(180);
delay(2000);
Serial.println("giro izquierda: ");
incoming=0;
}


if(incoming==5){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(45);
delay(2000);
Serial.println("giro camio-san: ");
incoming=0;
}

if(incoming==6){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(50);
delay(2000);
Serial.println("giro camion-san: ");
incoming=0;
}

if(incoming == 0) {
  der.detach();
  izq.detach(); 
  Serial.println("paro: ");
  Serial.println(" ");
  }
  }
}
