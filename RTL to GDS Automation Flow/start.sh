#!/bin/bash
# RTL2GDS Web App - Start Script
# Run this every time you want to use the application

echo ""
echo "╔══════════════════════════════════════════╗"
echo "║        RTL2GDS Web App Launcher          ║"
echo "╚══════════════════════════════════════════╝"
echo ""

# Check Docker is running
if ! docker info > /dev/null 2>&1; then
    echo "[ERROR] Docker is not running!"
    echo "  → Open Docker Desktop on Windows first"
    echo "  → Wait for the green 'Engine running' icon"
    echo "  → Then run this script again"
    exit 1
fi
echo "[OK] Docker is running"

# Check OpenLane exists
if [ ! -d "$HOME/OpenLane" ]; then
    echo "[ERROR] OpenLane not found at ~/OpenLane"
    echo "  → Follow the installation guide in README.md"
    exit 1
fi
echo "[OK] OpenLane found"

# Check dependencies
python3 -c "import flask, flask_cors, flask_jwt_extended" 2>/dev/null
if [ $? -ne 0 ]; then
    echo "[INFO] Installing Python dependencies..."
    pip3 install flask flask-cors flask-jwt-extended --break-system-packages
fi
echo "[OK] Dependencies ready"

echo ""
echo "  ➜  Website: http://localhost:5000"
echo "  ➜  Login:   admin / admin123"
echo "  ➜  Press Ctrl+C to stop"
echo ""

cd "$(dirname "$0")"
python3 app.py
