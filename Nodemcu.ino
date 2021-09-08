#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

char auth[]= "PO-JIUHW_6JO9C-FTYHJjiunVjNKoE-T";

char ssid[]="Airtlewifi";

char pass[]="snk98yuh";

SoftwareSerial s(D6,D5);//(Rx,Tx)

int room_location;

void setup() {

// put your setup code here, to run once:

s.begin(9600);

Serial.begin(9600);

Blynk.begin(auth,ssid,pass);

}

void loop() {

// put your main code here, to run repeatedly:

s.write("s");

if(s.available()>0){

room_location=s.read();

Serial.println(room_location);

if(room_location ==1){

Blynk.virtualWrite(V4,room_location);

Blynk.notify("TAB is in room 1");

}

else if(room_location ==2){

Blynk.virtualWrite(V4,room_location);

Blynk.notify("Mobile is in room 2");

}

else {

Blynk.virtualWrite(V4,room_location);

Blynk.notify("TAB is in room 2");

}

}

}
