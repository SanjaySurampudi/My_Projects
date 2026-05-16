# OpenLane Flow — All 42 Steps Explained

This document explains every step of the RTL to GDS flow that runs when you submit a design.

---

## Phase 1: Synthesis (Steps 1-2)

### Step 1 — Logic Synthesis (Yosys)
Converts your Verilog RTL code into a gate-level netlist using the sky130A standard cell library. Yosys performs:
- Parsing and elaboration of Verilog
- Technology mapping to sky130 cells
- Logic optimization
- Output: synthesized netlist (.v)

### Step 2 — Static Timing Analysis after Synthesis (OpenSTA)
Checks if the synthesized design meets timing constraints. Analyzes setup and hold times across all paths.

---

## Phase 2: Floorplanning (Steps 3-6)

### Step 3 — Initial Floorplanning (OpenROAD)
Defines the die area, core area, and places I/O pins. Sets up the physical boundaries of the chip based on your config.json settings (DIE_AREA, FP_CORE_UTIL).

### Step 4 — IO Placement
Places input/output pads around the periphery of the die.

### Step 5 — Tap and Decap Cell Insertion
Inserts tap cells (connect substrate to power/ground to prevent latch-up) and decoupling capacitors (stabilize power supply).

### Step 6 — Power Distribution Network (PDN) Generation
Creates the power grid — horizontal and vertical metal stripes that distribute VDD and GND across the entire chip.

---

## Phase 3: Placement (Steps 7-11)

### Step 7 — Global Placement (OpenROAD)
Roughly places all standard cells within the core area. Minimizes wire length but may have overlaps.

### Step 8 — Static Timing Analysis after Global Placement
Checks timing after rough placement to identify critical paths.

### Step 9 — Placement Resizer — Design Optimizations
Optimizes the design by resizing cells, adding buffers, and splitting nets to fix timing and DRC violations.

### Step 10 — Detailed Placement (OpenROAD)
Legalizes placement — removes all overlaps and snaps cells to placement grid. Final cell locations are fixed.

### Step 11 — Static Timing Analysis after Detailed Placement
Verifies timing after final placement.

---

## Phase 4: Clock Tree Synthesis (Steps 12-14)

### Step 12 — Clock Tree Synthesis (OpenROAD CTS)
Builds a balanced clock distribution network — a tree of buffers that distributes the clock signal to all flip-flops with minimal skew.

### Step 13 — Static Timing Analysis after CTS
Verifies timing with the actual clock tree in place.

### Step 14 — Placement Resizer — Timing Optimizations
Further optimizes placement and sizing specifically to fix timing violations revealed after CTS.

---

## Phase 5: Routing (Steps 15-24)

### Step 15 — Global Routing Resizer — Design Optimizations
Pre-routing optimizations to fix design rule violations before detailed routing.

### Step 16 — Static Timing Analysis (post-resize)

### Step 17 — Global Routing Resizer — Timing Optimizations

### Step 18 — Static Timing Analysis

### Step 19 — Global Routing (FastRoute)
Determines approximate routes for all wires through a grid-based routing graph. Does not generate actual metal shapes yet.

### Step 20 — Antenna Rule Check and Repair
Checks for antenna violations (long metal wires that accumulate charge during manufacturing and damage gate oxide). Inserts antenna diodes to fix violations.

### Step 21 — Static Timing Analysis after Global Routing

### Step 22 — Fill Insertion
Adds metal fill shapes to meet density requirements for chemical-mechanical polishing (CMP) during manufacturing.

### Step 23 — Detailed Routing (TritonRoute)
Generates exact metal wire geometries for every connection. This is the most computationally intensive step. Output: final routed DEF file.

### Step 24 — Wire Length Check
Verifies all wire lengths are within acceptable limits.

---

## Phase 6: Signoff (Steps 25-31)

### Step 25 — SPEF Extraction at Min Corner
Extracts parasitic resistance and capacitance values at the minimum process corner.

### Step 26 — Multi-Corner Static Timing Analysis (Min)
Timing analysis at minimum process/voltage/temperature corner.

### Step 27 — SPEF Extraction at Max Corner

### Step 28 — Multi-Corner Static Timing Analysis (Max)

### Step 29 — SPEF Extraction at Nominal Corner

### Step 30 — Multi-Corner Static Timing Analysis (Nominal)

### Step 31 — Single-Corner Static Timing Analysis
Final timing signoff at the nominal corner.

---

## Phase 7: Physical Verification (Steps 32-42)

### Step 32 — IR Drop Report
Analyzes voltage drop across the power grid to ensure all cells receive adequate supply voltage.

### Step 33 — Magic GDSII Stream Out
Converts the layout to GDSII format using Magic VLSI tool. This generates the final chip layout file.

### Step 34 — KLayout GDSII Stream Out
Alternative GDSII generation using KLayout for cross-verification.

### Step 35 — XOR Check (KLayout vs Magic)
Compares the two GDSII files using XOR operation. Any differences indicate a problem. Should show: "No XOR differences."

### Step 36 — Magic SPICE Export from LEF
Extracts SPICE netlist from the layout for LVS comparison.

### Step 37 — Powered Verilog Writing
Generates a Verilog netlist that includes power pins for LVS.

### Step 38 — Verilog Writing
Writes the final gate-level Verilog netlist.

### Step 39 — Layout vs Schematic (LVS)
Compares the extracted layout netlist against the schematic netlist to verify they match. Critical for manufacturing sign-off.

### Step 40 — Magic Design Rule Check (DRC)
Verifies the layout follows all manufacturing rules (minimum widths, spacings, enclosures, etc.) for the sky130A process. Should show: "No DRC violations."

### Step 41 — Antenna Rule Check (OpenROAD ARC)
Final antenna rule verification on the completed layout.

### Step 42 — Circuit Validity Checker (ERC)
Electrical rule check — verifies there are no floating inputs, short circuits, or other electrical violations.

---

## Final Output

After all 42 steps complete successfully, you get:

| File | Description |
|------|-------------|
| `*.gds` | GDSII layout file — open in KLayout |
| `*.lef` | Abstract layout for integration |
| `*.spef` | Parasitics for timing analysis |
| `metrics.csv` | Design metrics summary |
| `manufacturability.rpt` | Manufacturability report |

---

## Understanding the Results

**[SUCCESS]: Flow complete** — All steps passed, your design is ready!

**Key metrics to check:**
- **No DRC violations** — Layout meets manufacturing rules
- **No LVS errors** — Layout matches schematic  
- **No setup/hold violations** — Timing requirements met
- **No XOR differences** — GDSII files are consistent
