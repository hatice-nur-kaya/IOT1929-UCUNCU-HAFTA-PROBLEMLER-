#include <SPI.h>                        
#include <MFRC522.h>                   
#define k 4                        
#define m 3
MFRC522 rfid(10,9);            
byte kart[4] = {199,221,56,44};          


void setup() 
{
  Serial.begin(9600);                     
  SPI.begin();                            
  rfid.PCD_Init();                        
  pinMode(k,OUTPUT);
 pinMode(m,OUTPUT);    
}

void loop() 
{
        digitalWrite(m,0);
        digitalWrite(k,0);
  if ( ! rfid.PICC_IsNewCardPresent())    
    return;
  if ( ! rfid.PICC_ReadCardSerial())     
    return;

  if (rfid.uid.uidByte[0] == kart[0] &&     

    rfid.uid.uidByte[1] == kart[1] &&
    rfid.uid.uidByte[2] == kart[2] &&
    rfid.uid.uidByte[3] == kart[3] ) {
             Serial.print("İyi günler HATİCE NUR HANIM!\n");
           digitalWrite(m,HIGH);
          delay(1000);
          digitalWrite(k,LOW);
    }

    else{                                
      Serial.println("Kartınız tanımlanamadı!");
        digitalWrite(k,1);
        digitalWrite(m,0);
        delay(2000);
    }
  rfid.PICC_HaltA();
}
