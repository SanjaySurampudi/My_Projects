# Smart Home Automation using Arduino and Bluetooth

A Bluetooth-based Smart Home Automation project using **Arduino UNO**, **HC-05 Bluetooth Module**, and **4-Channel Relay Module**.  
This system allows users to control home appliances wirelessly through a smartphone using Bluetooth commands.

---

# 📌 Features

- Wireless appliance control using Bluetooth
- Control up to 4 devices independently
- Easy smartphone operation
- Low-cost home automation system
- Beginner-friendly Arduino project
- Real-time relay switching

---

# 🛠 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-05 Bluetooth Module | 1 |
| 4-Channel Relay Module | 1 |
| LEDs / Bulbs / Appliances | 4 |
| Jumper Wires | As required |
| 5V Power Supply | 1 |
| Smartphone | 1 |

---

# 🔌 Pin Connections

## Relay Connections

| Relay Module Pin | Arduino UNO |
|---|---|
| IN1 | D10 |
| IN2 | D9 |
| IN3 | D8 |
| IN4 | D7 |

---

## HC-05 Bluetooth Connections

| HC-05 Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | RX (D0) |
| RXD | TX (D1) |

---

# 📱 Bluetooth Commands

| Command | Action |
|---|---|
| A | Relay 1 ON |
| a | Relay 1 OFF |
| B | Relay 2 ON |
| b | Relay 2 OFF |
| C | Relay 3 ON |
| c | Relay 3 OFF |
| D | Relay 4 ON |
| d | Relay 4 OFF |

---

# 💻 Arduino Code

```cpp
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
```

---

# 🚀 How to Use

1. Connect the HC-05 and relay module to Arduino UNO
2. Upload the Arduino code
3. Pair HC-05 with your smartphone
4. Open a Bluetooth terminal application
5. Send commands to control appliances

---

# 📲 Recommended Bluetooth Apps

- Serial Bluetooth Terminal
- Bluetooth Electronics
- Arduino Bluetooth Controller

---

# 🔑 HC-05 Default Password

```text
1234
```

or

```text
0000
```

---

# ⚠ Important Notes

- Disconnect HC-05 TX/RX before uploading code
- Reconnect after uploading
- Most relay modules are ACTIVE LOW
- Be careful while handling AC appliances
- Use proper insulation and safety measures

---

# 📚 Applications

- Smart Home Systems
- Wireless Appliance Control
- Home Automation Learning
- IoT Mini Projects
- Arduino Automation Projects

---

# 🔮 Future Improvements

- Voice control integration
- Mobile app development
- WiFi and IoT support
- Sensor-based automation
- Google Assistant integration

---

# 👨‍💻 Author

Sanjay Surampudi

---

# 📄 License

This project is open-source and available under the MIT License.
