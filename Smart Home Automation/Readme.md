# Smart Home Automation System using Arduino & Bluetooth

A Bluetooth-based Smart Home Automation System built using **Arduino UNO**, **HC-05 Bluetooth Module**, and **4-Channel Relay Module**.  
This project allows users to wirelessly control home appliances using a smartphone Bluetooth application.

---

## 📌 Features

- Control up to 4 electrical appliances
- Wireless communication using Bluetooth
- Easy smartphone control
- Low-cost and beginner-friendly project
- Real-time ON/OFF switching
- Expandable for IoT applications

---

## 🛠 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-05 Bluetooth Module | 1 |
| 4-Channel Relay Module | 1 |
| LEDs / Bulbs / Appliances | 4 |
| Jumper Wires | As required |
| Power Supply | 5V |
| Smartphone with Bluetooth | 1 |

---

## 🔌 Circuit Diagram

Connect the components as shown in the circuit diagram.

### HC-05 Connections

| HC-05 Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | RX (D0) |
| RXD | TX (D1) |

### Relay Connections

| Relay Module | Arduino Pin |
|---|---|
| IN1 | D10 |
| IN2 | D9 |
| IN3 | D8 |
| IN4 | D7 |

---

## 📱 Bluetooth Commands

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

## 💻 Arduino Code

Upload the Arduino sketch to the UNO board using Arduino IDE.

```cpp
char data = 0;

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

    if (data == 'A')
      digitalWrite(relay1, LOW);

    if (data == 'a')
      digitalWrite(relay1, HIGH);

    if (data == 'B')
      digitalWrite(relay2, LOW);

    if (data == 'b')
      digitalWrite(relay2, HIGH);

    if (data == 'C')
      digitalWrite(relay3, LOW);

    if (data == 'c')
      digitalWrite(relay3, HIGH);

    if (data == 'D')
      digitalWrite(relay4, LOW);

    if (data == 'd')
      digitalWrite(relay4, HIGH);
  }
}
```

---

## 📲 Mobile Applications

You can use any Bluetooth terminal application:

- Serial Bluetooth Terminal
- Bluetooth Electronics
- Arduino Bluetooth Controller

---

## 🚀 How to Run

1. Connect all components properly
2. Upload the Arduino code
3. Pair HC-05 with smartphone
4. Open Bluetooth terminal app
5. Send commands to control appliances

### Default HC-05 Password

```text
1234
```

or

```text
0000
```

---

## ⚠ Important Notes

- Disconnect HC-05 TX/RX pins before uploading code
- Reconnect after uploading
- Relay modules are usually ACTIVE LOW
- Use caution while handling AC appliances

---

## 📚 Applications

- Smart Home Systems
- Wireless Appliance Control
- Home Automation Projects
- IoT Learning Projects
- Mini Engineering Projects

---

## 🔮 Future Improvements

- Voice control integration
- WiFi/IoT support
- Mobile app development
- Sensor-based automation
- Google Assistant / Alexa integration

---

## 👨‍💻 Author

Sanjay Surampudi

---

## 📄 License

This project is open-source and available under the MIT License.