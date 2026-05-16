# Bluetooth Controlled Robot Car using Arduino

This project is a simple Bluetooth-controlled robot car built using an Arduino UNO, HC-05 Bluetooth module, and motor driver.  
The robot receives commands from a smartphone via Bluetooth and performs movements like forward, backward, left, right, and stop.

---

# 📌 Features

- Wireless Bluetooth control
- Forward and backward movement
- Left and right turning
- Stop functionality
- Easy to build and program
- Beginner-friendly Arduino robotics project

---

# 🛠 Components Required

| Component | Quantity |
|---|---|
| Arduino UNO | 1 |
| HC-05 Bluetooth Module | 1 |
| L298N / Motor Driver | 1 |
| DC Motors | 2 |
| Robot Chassis | 1 |
| Wheels | 2 |
| Battery Pack | 1 |
| Jumper Wires | As required |

---

# 🔌 Pin Connections

## Arduino to Motor Driver

| Arduino Pin | Function |
|---|---|
| D13 | Left Motor Forward |
| D12 | Left Motor Reverse |
| D11 | Right Motor Forward |
| D10 | Right Motor Reverse |

---

## HC-05 Bluetooth Module

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
| S | Stop Robot |

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

# 🚀 How to Use

1. Connect all components properly
2. Upload the code to Arduino UNO
3. Pair HC-05 with your smartphone
4. Open a Bluetooth controller app
5. Send commands to control the robot

---

# 📲 Recommended Bluetooth Apps

- Serial Bluetooth Terminal
- Arduino Bluetooth Controller
- Bluetooth Electronics

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

- Disconnect HC-05 TX/RX wires before uploading code
- Reconnect them after uploading
- Use an external battery for motors
- Do not power motors directly from Arduino UNO

---

# 📚 Applications

- Bluetooth Robot Car
- Arduino Robotics Projects
- Wireless Vehicle Control
- Educational Robotics
- Beginner Automation Projects

---

# 🔮 Future Improvements

- Obstacle Avoidance
- Voice Control
- Mobile App Interface
- WiFi-Based Control
- Line Following Robot

---

# 👨‍💻 Author

Sanjay Surampudi

---

# 📄 License

This project is open-source and available under the MIT License.
