# RTL2GDS Web Application
### Automated RTL to GDSII Design Flow using OpenLane & sky130A PDK

<div align="center">

![RTL2GDS Banner](docs/banner.png)

[![Python](https://img.shields.io/badge/Python-3.10+-blue?style=for-the-badge&logo=python)](https://python.org)
[![Flask](https://img.shields.io/badge/Flask-3.0-black?style=for-the-badge&logo=flask)](https://flask.palletsprojects.com)
[![Docker](https://img.shields.io/badge/Docker-Required-2496ED?style=for-the-badge&logo=docker)](https://docker.com)
[![OpenLane](https://img.shields.io/badge/OpenLane-v1.0-green?style=for-the-badge)](https://github.com/The-OpenROAD-Project/OpenLane)
[![PDK](https://img.shields.io/badge/PDK-sky130A-orange?style=for-the-badge)](https://github.com/google/skywater-pdk)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](LICENSE)

**A full-stack web application that automates the complete RTL to GDSII physical design flow.**  
Write Verilog, run synthesis, placement, routing — and get your GDS layout file, all from a browser.

[Features](#features) • [Architecture](#architecture) • [Installation](#installation) • [Usage](#usage) • [Flow Steps](#flow-steps) • [Screenshots](#screenshots)

</div>

---

## What is RTL to GDS?

RTL (Register Transfer Level) to GDS (GDSII) is the complete VLSI physical design flow that transforms a hardware description written in Verilog into a manufacturable chip layout file.

```
Verilog RTL  →  Synthesis  →  Floorplan  →  Placement  →  Routing  →  GDSII Layout
```

This project automates all 42 steps of the OpenLane flow through a user-friendly web interface.

---

## Features

- **Write or Upload Verilog** — Type code directly in the browser editor or upload `.v` files
- **Smart Auto-Config** — Automatically generates `config.json` by analyzing your Verilog (detects clock ports, estimates die area)
- **Custom JSON Config** — Write or upload your own `config.json` for full control
- **Live Log Streaming** — Watch all 42 OpenLane steps execute in real time in the browser
- **Progress Bar** — Visual progress tracking across all flow steps
- **KLayout Integration** — One-click command to open the final GDS layout in KLayout
- **GDS Download** — Download the GDSII file directly from the browser
- **User Authentication** — JWT-based login so only authorized users can run flows
- **Jobs History** — Track all submitted designs and their status
- **Public Access** — Share via Cloudflare Tunnel or Ngrok for access from any device
- **Built-in Examples** — XOR gate, AND gate, 2:1 MUX, 4-bit Counter, ALU

---

## Architecture

```
┌─────────────────────────────────────────────────────────┐
│                    User's Browser                        │
│         (Any Device via Cloudflare/Ngrok URL)           │
└──────────────────────┬──────────────────────────────────┘
                       │ HTTPS
┌──────────────────────▼──────────────────────────────────┐
│              Cloudflare Tunnel / Ngrok                   │
│              (Free Public URL)                           │
└──────────────────────┬──────────────────────────────────┘
                       │
┌──────────────────────▼──────────────────────────────────┐
│           Flask Backend (localhost:5000)                  │
│   • JWT Authentication    • Auto Config Generator        │
│   • File Upload Handler   • Job Manager                  │
│   • GDS File Server       • API Routes                   │
└──────────────────────┬──────────────────────────────────┘
                       │ docker run
┌──────────────────────▼──────────────────────────────────┐
│           OpenLane Docker Container                       │
│   • Synthesis (Yosys)     • Floorplanning (OpenROAD)    │
│   • Placement (OpenROAD)  • Clock Tree Synthesis         │
│   • Global Routing        • Detailed Routing             │
│   • DRC / LVS / ERC      • GDSII Generation (Magic)     │
└──────────────────────┬──────────────────────────────────┘
                       │
┌──────────────────────▼──────────────────────────────────┐
│           sky130A PDK (SkyWater 130nm)                   │
│           Standard Cell Library                          │
└─────────────────────────────────────────────────────────┘
```

---

## Prerequisites

Before installing, make sure you have:

| Requirement | Version | Purpose |
|-------------|---------|---------|
| Windows 10/11 | Latest | Host OS |
| WSL2 (Ubuntu) | 20.04+ | Linux environment |
| Docker Desktop | Latest | Run OpenLane container |
| Python | 3.10+ | Flask backend |
| OpenLane | v1.0 | RTL to GDS flow |
| sky130A PDK | Latest | Process design kit |
| KLayout | 0.28+ | GDS viewer |

---

## Installation

### Step 1 — Install WSL2

Open PowerShell as Administrator and run:
```powershell
wsl --install
```
Restart your computer, then set up Ubuntu username and password.

### Step 2 — Install Docker Desktop

1. Download from [docker.com](https://www.docker.com/products/docker-desktop/)
2. Install and restart your computer
3. Open Docker Desktop — make sure it shows **Engine running** (green icon)
4. Go to Settings → Resources → WSL Integration → Enable for Ubuntu

### Step 3 — Install OpenLane

Open WSL2 Ubuntu terminal:
```bash
# Install dependencies
sudo apt update && sudo apt install -y git python3 python3-pip

# Clone OpenLane
git clone https://github.com/The-OpenROAD-Project/OpenLane.git ~/OpenLane
cd ~/OpenLane

# Pull the Docker image and install PDK
make pull-openlane
make pdk
```
> ⚠️ This takes 20-30 minutes and requires ~10GB disk space.

### Step 4 — Install KLayout

```bash
sudo apt install -y klayout
```

### Step 5 — Clone This Repository

```bash
git clone https://github.com/projectspace121/rtl2gds-webapp.git ~/rtl2gds
cd ~/rtl2gds
```

### Step 6 — Install Python Dependencies

```bash
pip3 install flask flask-cors flask-jwt-extended --break-system-packages
```

### Step 7 — Start the Application

**Terminal 1 — Start Flask server:**
```bash
cd ~/rtl2gds
python3 app.py
```

**Terminal 2 — Start public tunnel (optional, for sharing):**
```bash
ngrok http 5000
# OR
cloudflared tunnel --url http://localhost:5000
```

**Open in browser:**
```
http://localhost:5000
```

---

## Usage

### Login

Default credentials:

| Username | Password | Role |
|----------|----------|------|
| `admin` | `admin123` | Administrator |
| `sanjay` | `vlsi2026` | User |

> ⚠️ Change these passwords in `app.py` before deploying!

### Submit a Design

**Option A — Write Code:**
1. Enter a design name (e.g., `my_xor`)
2. Click an example chip (XOR, AND, MUX, Counter, ALU) or write your own Verilog
3. Optionally switch to the **Config (.json)** tab to customize settings
4. Click **Run RTL → GDS Flow**

**Option B — Upload Files:**
1. Switch to **Upload Files** mode
2. Drag & drop your `.v` Verilog file
3. Optionally upload a `config.json` (auto-generated if not provided)
4. Click **Run RTL → GDS Flow**

### Monitor Progress

- Watch live logs update in real time in the right panel
- Progress bar shows current step out of 42
- Step names displayed as flow progresses

### Get Your GDS Output

When the flow shows **[SUCCESS]: Flow complete**:

1. Click **🔬 Open in KLayout** button
2. Copy the command shown in the popup
3. Paste it in your WSL2 terminal
4. KLayout will open showing your chip layout

**OR** click **⬇ Download GDS** to save the file directly.

---

## Flow Steps

The OpenLane flow runs 42 automated steps:

| Phase | Steps | Tools Used |
|-------|-------|-----------|
| **Synthesis** | 1-2 | Yosys, OpenSTA |
| **Floorplanning** | 3-6 | OpenROAD, PDN |
| **Placement** | 7-11 | OpenROAD, Resizer |
| **Clock Tree Synthesis** | 12-14 | OpenROAD CTS |
| **Routing** | 15-24 | OpenROAD, FastRoute |
| **Signoff** | 25-31 | SPEF Extraction, STA |
| **Physical Verification** | 32-42 | Magic, KLayout, ERC |

---

## Project Structure

```
rtl2gds-webapp/
├── app.py                  # Flask backend server
├── requirements.txt        # Python dependencies
├── frontend/
│   └── index.html          # Complete frontend (HTML/CSS/JS)
├── docs/
│   ├── banner.png          # Project banner
│   └── screenshots/        # UI screenshots
├── examples/
│   ├── my_xor.v            # XOR gate example
│   ├── my_counter.v        # Counter example
│   └── my_alu.v            # ALU example
├── .gitignore              # Git ignore rules
├── LICENSE                 # MIT License
└── README.md               # This file
```

---

## API Reference

| Endpoint | Method | Auth | Description |
|----------|--------|------|-------------|
| `/` | GET | No | Serve frontend |
| `/api/login` | POST | No | Login, get JWT token |
| `/api/run` | POST | Yes | Submit design for flow |
| `/api/status/<job_id>` | GET | Yes | Get job status and logs |
| `/api/jobs` | GET | Yes | List all jobs |
| `/api/preview_config` | POST | Yes | Preview auto-generated config |
| `/api/download_gds/<job_id>` | GET | Yes | Download GDS file |
| `/api/add_user` | POST | Admin | Add new user |

---

## Configuration

### Adding Users

Edit `app.py` and add to the `USERS` dictionary:
```python
from werkzeug.security import generate_password_hash

USERS = {
    'admin':   generate_password_hash('your_password'),
    'newuser': generate_password_hash('newpassword'),
}
```

### Custom Docker Image

If your OpenLane version differs, update in `app.py`:
```python
DOCKER_IMAGE = 'ghcr.io/the-openroad-project/openlane:YOUR_TAG-amd64'
```

Find your tag:
```bash
cd ~/OpenLane && python3 dependencies/get_tag.py
```

### Auto-Config Logic

The auto-config generator in `app.py` analyzes your Verilog to:
- Detect clock ports (`clk`, `clock`)
- Count input/output ports
- Detect sequential vs combinational logic
- Scale die area accordingly

---

## Troubleshooting

### Server won't start
```bash
# Check Python version
python3 --version  # must be 3.10+

# Reinstall dependencies
pip3 install flask flask-cors flask-jwt-extended --break-system-packages
```

### Flow fails immediately
```bash
# Make sure Docker Desktop is running on Windows
# Check OpenLane directory exists
ls ~/OpenLane

# Test Docker works
docker ps
```

### Cannot reach server from phone/other device
```bash
# Make sure ngrok or cloudflared is running in a second terminal
ngrok http 5000
```

### KLayout command fails
```bash
# Run from OpenLane directory
cd ~/OpenLane
klayout designs/my_xor/runs/*/results/final/gds/my_xor.gds
```

### Port 5000 already in use
```bash
# Change port in app.py
app.run(debug=False, port=5001, threaded=True)
```

---

## Running Every Time

**Each time you want to use the app:**

1. Open **Docker Desktop** on Windows (wait for green icon)
2. Open **WSL2 Terminal 1:**
   ```bash
   cd ~/rtl2gds && python3 app.py
   ```
3. Open **WSL2 Terminal 2** (for public access):
   ```bash
   ngrok http 5000
   ```
4. Open browser → `http://localhost:5000`

---

## Technologies Used

| Technology | Purpose |
|------------|---------|
| **Python / Flask** | Backend web server |
| **Flask-JWT-Extended** | User authentication |
| **Flask-CORS** | Cross-origin requests |
| **OpenLane** | RTL to GDS flow automation |
| **Docker** | Container for OpenLane tools |
| **sky130A PDK** | SkyWater 130nm process design kit |
| **Yosys** | Logic synthesis |
| **OpenROAD** | Placement, routing, STA |
| **Magic VLSI** | DRC, LVS, GDS streaming |
| **KLayout** | GDS layout viewer |
| **Ngrok / Cloudflare** | Public tunnel for web access |
| **HTML/CSS/JS** | Frontend (no framework) |

---

## Examples Included

### XOR Gate
```verilog
module my_xor (
    input  wire a,
    input  wire b,
    output wire y
);
    assign y = a ^ b;
endmodule
```

### 4-bit Counter
```verilog
module my_counter (
    input  wire       clk,
    input  wire       rst,
    output reg  [3:0] count
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            count <= 4'b0000;
        else
            count <= count + 1;
    end
endmodule
```

---

## License

This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

---

## Author

**Sanjay** — [@projectspace121](https://github.com/projectspace121)

> Built as part of a VLSI design project demonstrating the complete RTL to GDS physical design flow using open-source EDA tools.

---

## Acknowledgements

- [The OpenROAD Project](https://theopenroadproject.org/) — OpenLane flow
- [Google / SkyWater](https://github.com/google/skywater-pdk) — sky130A PDK
- [Efabless](https://efabless.com/) — OpenLane development
- [KLayout](https://www.klayout.de/) — GDS viewer

---

<div align="center">
⭐ Star this repo if it helped you learn VLSI design flow!
</div>
