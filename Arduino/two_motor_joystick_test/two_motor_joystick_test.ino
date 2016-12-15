const byte LMF = 11;// PWM Left motor forward pin
const byte LMR = 9;// PWM Left motor Reverse pin
const byte RMF = 3;// PWM Right motor forward pin
const byte RMR = 12;// PWM Right motor reverse pin

void setup()
{
  //Serial.begin(115200);
  pinMode(LMF, OUTPUT);                                
  pinMode(RMF, OUTPUT);
  pinMode(LMR, OUTPUT);                                
  pinMode(RMR, OUTPUT);
}

void loop()
{
  move(analogRead(A0), analogRead(A1), 10, 10, false, false);
}

//FR = Forward/Reverse pot
//T = turning pot
//FRdead = deadzone for F/R pot
//Tdead = deadzone for turning pot
//FRflip = if the joystick is upside-down, user can flip it
//Tflip = if the joystick is upside-down, user can flip it
//type = Single_Joy or Duel_Joy

void move(int FR, int T, int FRdead, int Tdead, boolean FRflip, boolean Tflip)
{ 
  int DRV1, DRV2, STRL, STRR;

  if (FRflip)
    FR = 1023 - FR;

  if (Tflip)
    T = 1023 - T;

  if (T >= (511 + Tdead)) // Left
  {
    STRL = ((T-511) / 2) - 1;  // ((511 + Tdead) - T)/2;
    STRR = 255 - STRL;
  }
  else if (T <= (511 - Tdead)) // Right
  {
    STRR = (511-T) / 2;  // ...
    STRL = 255 - STRR;
  }
  else
  {
    STRR = 0;
    STRL = 0;
  }

  if (FR > (511 + FRdead))
    DRV1 = (FR - 512) / 2;
  else if (FR < (511 - FRdead))
    DRV2 = (512 - FR) / 2;

  if(FR > (511 + FRdead))//forwards               
  {
    //Serial.println("Forward with turning"); 
    analogWrite(LMF, DRV1 - STRL); 
    analogWrite(RMF, DRV1 - STRR);   
    digitalWrite(LMR, LOW); // can be cut out if motor wires are pulled low
    digitalWrite(RMR, LOW); // can be cut out if motor wires are pulled low
  }
  else if(FR < (511 - FRdead))//backwards               
  {
    //Serial.println("Reverse with turning"); 
    digitalWrite(LMF, LOW);// can be cut out if motor wires are pulled low 
    digitalWrite(RMF, LOW);// can be cut out if motor wires are pulled low   
    analogWrite(LMR, DRV2 - STRL); 
    analogWrite(RMR, DRV2 - STRR);   
  }
  else if((FR < (511 + FRdead) && FR > (511 - FRdead)) && T > (511 + Tdead))//left              
  {
    //Serial.println("360 left"); 
    digitalWrite(LMR, LOW); 
    analogWrite(RMR, STRR);   
    analogWrite(LMF, STRR); 
    digitalWrite(RMF, LOW);
  }
  else if((FR < (511 + FRdead) && FR > (511 - FRdead)) && T < (511 - Tdead))//right              
  {
    //Serial.println("360 right"); 
    analogWrite(LMR, STRL); 
    digitalWrite(RMR, LOW);   
    digitalWrite(LMF, LOW); 
    analogWrite(RMF, STRL);   
  }
  else //full stop
  { 
    digitalWrite(LMF, LOW); 
    digitalWrite(RMF, LOW);        
    digitalWrite(LMR, LOW); 
    digitalWrite(RMR, LOW);    
  }
}
