#include <RH_ASK.h>

#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()

{

driver.init();

Serial.begin(9600); // Debugging only

}

void loop()

{

const char *msg = "B";

driver.send(msg, strlen(msg));

driver.waitPacketSent();

{

delay(1000);

}

}
