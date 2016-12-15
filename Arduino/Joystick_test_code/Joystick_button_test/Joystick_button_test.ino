const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;
int val = 0;

void setup()
{
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

}

void loop()
{
 /* Serial.print("Switch: ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-Axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-Axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");\
  delay(500); */

  if (digitalRead(SW_pin) == 0)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }

  
  if (analogRead(X_pin) <= 200)
  {
    digitalWrite(12, HIGH);
  }
  else
  {
    digitalWrite(12, LOW);
  }

  if (analogRead(X_pin) >= 800)
  {
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }

/*  if (analogRead(Y_pin) <= 200)
  {
    digitalWrite(11, HIGH);
  }
  else
  {
    digitalWrite(11, LOW);
  } */
/* Sequence for dimming LED-------------------------------------------------- */
  if ((analogRead(Y_pin) < 490) && (analogRead(Y_pin)> 441))
  {
    analogWrite(11, 1);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin) < 441) && (analogRead(Y_pin) > 392))
  {
    analogWrite(11, 5);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin) < 392) && (analogRead(Y_pin) > 343))
  {
    analogWrite(11, 10);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 343 && (analogRead(Y_pin) > 294))
  {
    analogWrite(11, 20);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 294 && (analogRead(Y_pin) > 245))
  {
    analogWrite(11, 30);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 245 && (analogRead(Y_pin) > 196))
  {
    analogWrite(11, 40);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 196 && (analogRead(Y_pin) > 147))
  {
    analogWrite(11, 50);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 147 && (analogRead(Y_pin) > 98))
  {
    analogWrite(11, 60);
  }
  else
  {
    analogWrite(11, 0);
  }

  if ((analogRead(Y_pin)) < 98 && (analogRead(Y_pin) > 49))
  {
    analogWrite(11, 70);
  }
  else
  {
    analogWrite(11, 0);
  }
  if ((analogRead(Y_pin)) < 49 && (analogRead(Y_pin) >= 0))
  {
    analogWrite(11, 255);
  }
  else
  {
    analogWrite(11, 0);
  }
/* END Sequence for dimming LED-------------------------------------------------- */
 /* if (analogRead(Y_pin) >= 800)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }*/

 // val = analogRead(Y_pin);
 // analogWrite(11, val / 4);
  

 /* if (analogRead(Y_pin) >= 800)
  {
    analogWrite(9, (analogRead(Y_pin)%1000));
  }
  else
  {
    digitalWrite(9, LOW);
  }*/
  
}

