#include <SoftwareSerial.h>

SoftwareSerial xbee(2,3);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Start of program........");
  xbee.begin(9600);

}

void loop() 
{
  char temp = xbee.read();
  Serial.print("Character received: \n");
  Serial.print(temp);
  Serial.print("\n");
  delay(500);
}
