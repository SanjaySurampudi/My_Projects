# Installation Guide

Complete step-by-step installation for RTL2GDS Web Application.

---

## System Requirements

- **OS:** Windows 10 (Build 19041+) or Windows 11
- **RAM:** Minimum 8GB (16GB recommended)
- **Disk:** Minimum 20GB free space
- **Internet:** Required for initial setup

---

## Step 1 — Enable WSL2

Open **PowerShell as Administrator** and run:

```powershell
wsl --install
```

This installs WSL2 with Ubuntu. Restart your computer when prompted.

After restart, Ubuntu will open automatically. Set up your username and password.

**Verify WSL2 is working:**
```bash
wsl --list --verbose
# Should show Ubuntu with VERSION 2
```

---

## Step 2 — Install Docker Desktop

1. Download Docker Desktop from: https://www.docker.com/products/docker-desktop/
2. Run the installer
3. During installation, make sure **"Use WSL 2 instead of Hyper-V"** is checked
4. Restart your computer
5. Open Docker Desktop
6. Go to **Settings → Resources → WSL Integration**
7. Enable integration for **Ubuntu**
8. Click **Apply & Restart**

**Verify Docker works in WSL2:**
```bash
docker --version
docker ps
```

---

## Step 3 — Install OpenLane

Open WSL2 Ubuntu terminal and run:

```bash
# Update system
sudo apt update && sudo apt upgrade -y

# Install required packages
sudo apt install -y git python3 python3-pip make curl

# Clone OpenLane
git clone https://github.com/The-OpenROAD-Project/OpenLane.git ~/OpenLane
cd ~/OpenLane

# Pull Docker image (takes 10-15 minutes, ~5GB download)
make pull-openlane

# Install sky130A PDK (takes 15-20 minutes, ~5GB download)
make pdk
```

> ⏱️ Total time: approximately 30-45 minutes

**Verify OpenLane works:**
```bash
cd ~/OpenLane
make mount
# Should open OpenLane container shell
# Type: exit
```

---

## Step 4 — Install KLayout

```bash
sudo apt install -y klayout
```

**Verify KLayout:**
```bash
klayout --version
```

---

## Step 5 — Clone This Repository

```bash
git clone https://github.com/projectspace121/rtl2gds-webapp.git ~/rtl2gds
cd ~/rtl2gds
```

---

## Step 6 — Install Python Dependencies

```bash
pip3 install flask flask-cors flask-jwt-extended --break-system-packages
```

**Verify installation:**
```bash
python3 -c "import flask; print('Flask OK:', flask.__version__)"
python3 -c "import flask_jwt_extended; print('JWT OK')"
```

---

## Step 7 — Run a Test Flow

Test that everything works end-to-end:

```bash
# Start the server
cd ~/rtl2gds
python3 app.py
```

Open browser → `http://localhost:5000`

Login with `admin` / `admin123`

Click **XOR Gate** example → Click **Run RTL → GDS Flow**

You should see logs streaming. After 5-10 minutes you should see:
```
[SUCCESS]: Flow complete.
```

---

## Troubleshooting Installation

### WSL2 not installing
- Make sure Windows is updated to build 19041 or later
- Run: `winver` to check your Windows version

### Docker Desktop won't start
- Make sure Hyper-V or Virtual Machine Platform is enabled
- In PowerShell (Admin): `Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Hyper-V -All`

### `make pdk` fails
- Check disk space: `df -h`
- Need at least 10GB free in WSL2

### Python import errors
```bash
pip3 install --upgrade pip
pip3 install flask flask-cors flask-jwt-extended --break-system-packages --force-reinstall
```

### Port 5000 in use
```bash
# Find what's using port 5000
sudo lsof -i :5000
# Change port in app.py from 5000 to 5001
```

---

## Optional — Install Ngrok for Public Access

```bash
# Install
curl -sSL https://ngrok-agent.s3.amazonaws.com/ngrok.asc \
  | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null \
  && echo "deb https://ngrok-agent.s3.amazonaws.com buster main" \
  | sudo tee /etc/apt/sources.list.d/ngrok.list \
  && sudo apt update && sudo apt install ngrok -y

# Sign up at ngrok.com and get your authtoken
ngrok config add-authtoken YOUR_TOKEN

# Use (run alongside app.py in second terminal)
ngrok http 5000
```
