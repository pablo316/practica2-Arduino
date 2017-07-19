
#include <Servo.h>
//servomotores para cada rueda 
Servo izq;  
Servo der;


int pos = 0;    // variable to store the servo position

int incoming = 0;   // dato recibido desde el monitor serial o por bluetooth 

void setup() {
  Serial.begin(9600);
}

void loop() {

  // verificar si se reciben datos:
  if (Serial.available() > 0) {
    // leer dato recibido:
    incoming = Serial.parseInt();

    // mostramos el dato recibido:
    Serial.print("dato recibido: ");
    Serial.println(incoming);


//ingresar 1 avanzar
if(incoming==1){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(0);
delay(2000);
Serial.println("avanzar: ");
incoming=0;
}
//ingresar 2 retroceder
if(incoming==2){
izq.attach(9); 
der.attach(8);
izq.write(0);
der.write(180);
delay(2000);
Serial.println("retrocedio: ");
incoming=0;
}
//ingresar 3 giro en su eje a la derecha
if(incoming==3){
izq.attach(9); 
der.attach(8);
izq.write(0);
der.write(0);
delay(2000);
Serial.println("giro derecha: ");
incoming=0;
}
//ingresar 4 giro en su eje a la izquierda
if(incoming==4){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(180);
delay(2000);
Serial.println("giro izquierda: ");
incoming=0;
}

//ingresar 5 movimiento curva a la izquierda 
if(incoming==5){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(45);
delay(2000);
Serial.println("giro curva izquierda: ");
incoming=0;
}
//ingresar 6 movimiento curva a la derecha
if(incoming==6){
izq.attach(9); 
der.attach(8);
izq.write(180);
der.write(50);
delay(2000);
Serial.println("giro curva derecha: ");
incoming=0;
}
//ingresar 0 para detener motores
if(incoming == 0) {
  der.detach();
  izq.detach(); 
  Serial.println("detener: ");
  Serial.println(" ");
  }
  }
}
