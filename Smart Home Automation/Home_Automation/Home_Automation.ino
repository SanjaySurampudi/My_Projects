
char data = 0;

// Relay pins
int relay1 = 10;
int relay2 = 9;
int relay3 = 8;
int relay4 = 7;

void setup()
{
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // Relays OFF initially
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop()
{
  if (Serial.available())
  {
    data = Serial.read();

    // Relay 1
    if (data == 'A')
    {
      digitalWrite(relay1, LOW);
      Serial.println("Relay 1 ON");
    }

    if (data == 'a')
    {
      digitalWrite(relay1, HIGH);
      Serial.println("Relay 1 OFF");
    }

    // Relay 2
    if (data == 'B')
    {
      digitalWrite(relay2, LOW);
      Serial.println("Relay 2 ON");
    }

    if (data == 'b')
    {
      digitalWrite(relay2, HIGH);
      Serial.println("Relay 2 OFF");
    }

    // Relay 3
    if (data == 'C')
    {
      digitalWrite(relay3, LOW);
      Serial.println("Relay 3 ON");
    }

    if (data == 'c')
    {
      digitalWrite(relay3, HIGH);
      Serial.println("Relay 3 OFF");
    }

    // Relay 4
    if (data == 'D')
    {
      digitalWrite(relay4, LOW);
      Serial.println("Relay 4 ON");
    }

    if (data == 'd')
    {
      digitalWrite(relay4, HIGH);
      Serial.println("Relay 4 OFF");
    }
  }
}