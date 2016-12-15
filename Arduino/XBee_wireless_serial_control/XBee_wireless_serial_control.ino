/*********
*
*      ER_RemoteA  (Engineering & Robotics Remote Option)
*
*      XBee standalone transmitter sends analog joystick readings to an Arduino
*      connected receiver XBee.  Analog values are read from a pair of
*      Joysticks to drive a left and right motor in "tank mode".
*   
*      An Adafruit motorshield is connected to the Arduino UNO to handle motor direction control.
*      The motors used are VEX motors.
*
*      XBee communication occurs through Digital pins 14 & 15 (A0 & A1) through software serial
*      in order to leave TX & RX free for serial communication and debugging purposes.  There is alot
*      of debugging read outs that can be eliminated from the code.  Sub-routines could also be used to
*      clean up the code.
*
*      Adapted from the Arduino Cookbook:  Section 14.4
*      Date:  Aug. 15, 2013
*      Author:  Mylo Hildebrand
*
***********/

//#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial xbee(14,15); // RX, TX

//AF_DCMotor leftmotor(1);
//AF_DCMotor rightmotor(2);

void setup() {
  Serial.begin(9600);
 
  //Set the data rate for the SoftwareSerial port
  xbee.begin(9600);

  //configureRadio(); // check the return value if you need error handling
}

/*boolean configureRadio() {
// put the radio in command mode:
  while(xbee.read() >=0 );
 
  xbee.print("+++");
  delay(100);
  String ok_response = "OK\r"; // the response we expect.
// Read the text of the response into the response variable
  String response = String("");
 
  while (response.length() < ok_response.length()) {
    if (xbee.available() > 0) {
      response += (char) xbee.read();
    }
  }

// If we got the right response, configure the radio and return true.
  if (response.equals(ok_response)) {
    xbee.print("ATAP1\r"); // Enter API mode
    delay(100);
    xbee.print("ATCN\r");
    return true;
  }
  else {
    return false; // This indicates the response was incorrect.
  }
}*/

void loop() 
{

  int str = xbee.read();
  Serial.print(str);
  xbee.print("+++");
 /* if (xbee.available() >= 14) 
  { // Wait until we have a mouthful of data
    if (xbee.read() == 0x7E) 
    { // Start delimiter of a frame
  
    // Skip over the bytes in the API frame we don't care about
      for (int i = 0; i < 10; i++) 
      {
        xbee.read();
      }
    
    // The next two bytes are the high and low bytes of the sensor reading
      int leftHigh = xbee.read();
      Serial.print("HL:  ");
      Serial.println(leftHigh);
      int leftLow = xbee.read();
      Serial.print("LL:  ");
      Serial.println(leftLow);
      int leftValue = leftLow + (leftHigh * 256);
      Serial.print("AL:  ");
      Serial.println(leftValue);
    
      int rightHigh = xbee.read();
      Serial.print("HR:  ");
      Serial.println(rightHigh);
      int rightLow = xbee.read();
      Serial.print("LR:  ");
      Serial.println(rightLow);
      int rightValue = rightLow + (rightHigh * 256);
      Serial.print("AR:  ");
      Serial.println(rightValue);
    
    //Drive Functions Using Analog Joysticks.  Left for left side and right for right side.
    /*    int leftjoystick = map(leftValue, 0, 1023, -250, 250);
       
        if(leftjoystick > 50) // print stick values if either is TRUE
        {
            leftmotor.setSpeed(leftjoystick);
            leftmotor.run(BACKWARD);
        }
        else if(leftjoystick < -50) // print stick values if either is TRUE
        {
            leftmotor.setSpeed(abs(leftjoystick));
            leftmotor.run(FORWARD);
        }
        else
        {
            leftmotor.setSpeed(0);
        }
       
        int rightjoystick = map(rightValue, 0, 1023, -250, 250);
       
        if (rightjoystick > 50) // print stick values if either is TRUE
        {
            rightmotor.setSpeed(rightjoystick);
            rightmotor.run(FORWARD);
        }
        else if(rightjoystick < -50) // print stick values if either is TRUE
        {
            rightmotor.setSpeed(abs(rightjoystick));
            rightmotor.run(BACKWARD);
        }
        else
        {
            rightmotor.setSpeed(0);
        }*/
          delay(50);
     //   }
   // }
}
