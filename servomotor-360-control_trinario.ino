
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
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
myservo.attach(9); 
myservo.write(180);
delay(2000);
Serial.println("retrocedio: ");
incoming=0;
}

//ingresar 2 motor avanza
if(incoming==1){
  myservo.attach(9); 
  myservo.write(0);
  Serial.println("avanzo: ");
  delay(2000);
  incoming=0;
  }
  
if(incoming == 0) {
  myservo.detach(); 
  Serial.println("paro: ");
  Serial.println(" ");
  }

  

  }




  
  }
  



