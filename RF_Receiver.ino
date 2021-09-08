#include <RH_ASK.h>

#include <SPI.h> // Not actualy used but needed to compile

#include <SoftwareSerial.h>

SoftwareSerial s(5,6);//(Rx,Tx)

RH_ASK driver;

void setup()

{

driver.init();

s.begin(9600);

Serial.begin(9600); // Debugging only

}

void loop()

{

int room_location =0;

char buf[1];

uint8_t buflen = sizeof(buf);

if (driver.recv(buf, &buflen)) // Non-blocking

{

Serial.print("Message recieved: ");

Serial.println(buf[0]);

if (buf[0] == 'A'){Serial.print("TAB is in room 1\n");

room_location =1;}

else if

(buf[0] == 'B'){Serial.print("Mobile is in room 2\n");

room_location =2;}//

if(s.available()>0){

char c = s.read();

if(c=='s'){

s.write(room_location);

}

}

delay(1000);

}

}
