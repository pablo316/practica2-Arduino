#include <SoftwareSerial.h>
SoftwareSerial BT1(3, 2); // RX | TX
int n1=0;

void setup()
  {Serial.begin(115200);
   BT1.begin(115200);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   }



void loop() 
{ while (BT1.available() >0 )
  {char c = BT1.read();
  if (c == 71) 
  {Serial.println("peticion web enviada");
   delay(500);
   servidor();
     }
 }
 
}



void escribir(String text)
{BT1.print("AT+CIPSEND=0,");  
 BT1.println(text.length());
 if (BT1.find(">"))             // Si se recibe el mensaje
 {Serial.println(text);
  BT1.println(text);            //mandamos el mensaje por el wifi 
  delay(10);
  while ( BT1.available() > 0 ) 
  {if (  BT1.find("SEND OK") )  //buscamos "ok" y luego salimos
   break; 
  }
 }
}

void servidor(void) 
    { 
      int analog0=0;
      analog0=analogRead(A0);
      escribir("<!DOCTYPE HTML>");
      escribir("<html>");                                                  //una pagina web necesita esto <HTML> y </HTML> es el inicio y fin del documento
      escribir("<head><title>Test</title>");   
      escribir("<body> sensor:");
      escribir(String(analog0));
      escribir("</body>");
      
      escribir("</html>"); 
       delay(1);
       BT1.println("AT+CIPCLOSE=0");
       //delay(500);
    }
