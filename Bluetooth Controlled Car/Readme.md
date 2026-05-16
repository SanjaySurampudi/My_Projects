# Bluetooth Controlled Robot Car using Arduino

A simple Bluetooth-controlled robot car built using **Arduino UNO**, **HC-05 Bluetooth Module**, and **L298N Motor Driver**.  
The robot can move forward, backward, left, right, and stop using commands sent from a smartphone via Bluetooth.

---

# 📌 Features

- Wireless Bluetooth control
- Forward and backward movement
- Left and right turning
- Stop functionality
- Beginner-friendly robotics project
- Real-time motor control

---

# 🛠 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-05 Bluetooth Module | 1 |
| L298N Motor Driver | 1 |
| DC Motors | 2 |
| Robot Chassis | 1 |
| Wheels | 2 |
| Battery Pack | 1 |
| Jumper Wires | As required |

---

# 🔌 Circuit Connections

## Motor Driver to Arduino

| Arduino Pin | Function |
|---|---|
| D13 | Left Motor Forward |
| D12 | Left Motor Reverse |
| D11 | Right Motor Forward |
| D10 | Right Motor Reverse |

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
| F | Move Forward |
| B | Move Backward |
| L | Turn Left |
| R | Turn Right |
| S | Stop |

---

# 💻 Arduino Code

```cpp
char t;
 
void setup() {

  pinMode(13,OUTPUT);   // left motors forward
  pinMode(12,OUTPUT);   // left motors reverse
  pinMode(11,OUTPUT);   // right motors forward
  pinMode(10,OUTPUT);   // right motors reverse

  Serial.begin(9600);

  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
  
void loop() {

  if(Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
 
  if(t == 'F') {            
    // move forward
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
  }
 
  else if(t == 'B') {      
    // move backward
    digitalWrite(12,HIGH);
    digitalWrite(10,HIGH);
  }
  
  else if(t == 'L') {      
    // turn left
    digitalWrite(11,HIGH);
  }
 
  else if(t == 'R') {      
    // turn right
    digitalWrite(13,HIGH);
  }

  else if(t == 'S') {      
    // stop
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }

  delay(100);
}
```

---

# 📲 Mobile Applications

You can use any Bluetooth controller app:

- Serial Bluetooth Terminal
- Arduino Bluetooth Controller
- Bluetooth Electronics

---

# 🚀 How to Run

1. Assemble the robot chassis
2. Connect motors to L298N motor driver
3. Connect HC-05 to Arduino
4. Upload the Arduino code
5. Pair HC-05 with smartphone
6. Open Bluetooth app
7. Send movement commands

---

# 🔑 Default HC-05 Password

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
- Use proper battery supply for motors
- Avoid powering motors directly from Arduino

---

# 📚 Applications

- Bluetooth Robotics
- Wireless Vehicle Control
- Obstacle Avoidance Base Project
- Robotics Learning
- Arduino Mini Projects

---

# 🔮 Future Improvements

- Obstacle avoidance using ultrasonic sensor
- Voice control
- WiFi control using ESP8266
- Mobile app interface
- Line follower integration
- Camera streaming

---

# 👨‍💻 Author

Sanjay Surampudi

---

# 📄 License

This project is open-source and available under the MIT License.