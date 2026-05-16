# BCD to 7-Segment Display Decoder using Logic Gates in Proteus

This project implements a **BCD to 7-Segment Display Decoder** using basic digital logic gates in **Proteus Design Suite**.  
The circuit takes a 4-bit binary input and displays the corresponding decimal digit on a 7-segment display.

The decoder is designed manually using:
- AND Gates
- OR Gates
- XOR Gates
- NOT Gates

without using any dedicated decoder IC like 7447 or 4511.

---

# 📌 Features

- Manual implementation of BCD to 7-segment decoder
- Designed completely using logic gates
- Displays decimal digits from 0 to 9
- Built and simulated in Proteus
- Educational digital electronics project
- Beginner-friendly logic design project

---

# 🛠 Software Used

| Software | Purpose |
|---|---|
| Proteus Design Suite | Circuit design and simulation |

---

# 📂 Project Files

```text
7segment.pdsprj
README.md
```

---

# 🔢 Inputs and Outputs

## Inputs

The circuit uses 4 binary inputs:

| Input | Description |
|---|---|
| A | Least Significant Bit |
| B | Binary Input |
| C | Binary Input |
| D | Most Significant Bit |

---

## Output

- Common Cathode 7-Segment Display
- Segments:
  - A
  - B
  - C
  - D
  - E
  - F
  - G

---

# ⚙ Working Principle

The circuit converts a 4-bit Binary Coded Decimal (BCD) input into the corresponding output required to drive a 7-segment display.

Each segment of the display is controlled using Boolean expressions implemented with logic gates.

For example:

| Binary Input | Decimal Output |
|---|---|
| 0000 | 0 |
| 0001 | 1 |
| 0010 | 2 |
| 0011 | 3 |
| 0100 | 4 |
| 0101 | 5 |
| 0110 | 6 |
| 0111 | 7 |
| 1000 | 8 |
| 1001 | 9 |

---

# 🔌 Logic Gates Used

| Gate | Purpose |
|---|---|
| NOT Gate | Input inversion |
| AND Gate | Boolean multiplication |
| OR Gate | Boolean addition |
| XOR Gate | Exclusive logic operations |

---

# 🖥 Circuit Design

The Proteus circuit contains:

- Binary input switches
- Logic gate combinations
- 7-segment display
- Signal routing connections

Each segment is driven using manually derived Boolean equations.

---

# ▶ How to Run

1. Open the project in Proteus
2. Start simulation
3. Change binary inputs using switches
4. Observe corresponding digit on 7-segment display

---

# 📚 Concepts Used

- Digital Electronics
- Boolean Algebra
- Logic Gate Design
- Combinational Circuits
- BCD Encoding
- 7-Segment Display Interfacing

---

# 🎯 Applications

- Digital Display Systems
- Calculator Displays
- Embedded Systems
- Digital Counters
- Learning Digital Logic Design

---

# 🔮 Future Improvements

- Use Karnaugh Maps for optimization
- Implement hexadecimal display
- Add FPGA implementation
- Use decoder IC comparison
- PCB design implementation

---

# 👨‍💻 Author

Sanjay Surampudi

---

# 📄 License

This project is open-source and available under the MIT License.