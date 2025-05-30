# Component Placement Guide - ESP Sensor Hub v1.0

## Component Identification and Placement Reference

This guide provides detailed component identification and placement information for hand assembly of the ESP Sensor Hub.

## PCB Layout Overview

```
     USB-C (J1)
    ┌─────────────┐
    │   [PWR]     │  Status LEDs (L1-L4)
    │             │  ◄── Programming Header (J2)
    │    ESP32    │
    │   (U1)      │
    │             │  Test Points (TP1-TP7)
    │  [RST][BOOT]│  ◄── Reset/Boot Switches
    └─────────────┘
I2C Connectors     Power Jack (J5)
(J3, J4)
```

## Component Identification

### Integrated Circuits

#### U1 - ESP32-WROOM-32 Module
- **Package**: ESP32-WROOM-32 (39-pin module)
- **Orientation**: Pin 1 marked on PCB and module
- **Identification**: Large module with antenna area
- **Critical Notes**:
  - Antenna area must remain clear of copper
  - Pin 1 alignment is critical
  - Most expensive component - handle with care

#### U2 - AMS1117-3.3 Voltage Regulator
- **Package**: SOT-223 (4-pin)
- **Marking**: "AMS1117-3.3" or "117-33"
- **Orientation**: Tab aligns with thermal pad on PCB
- **Location**: Near power input connectors

### Passive Components (SMT)

#### Resistors (0603 Package)
- **R1, R2**: 10kΩ ±5% (Marking: "103")
  - **Function**: Pull-up resistors for I2C and reset
  - **Color**: Usually dark blue or black body
  
- **R3, R4, R5**: 330Ω ±5% (Marking: "331")
  - **Function**: Current limiting for status LEDs
  - **Location**: Near LED positions
  
- **R6, R7**: 4.7kΩ ±5% (Marking: "472") - **Bottom side**
  - **Function**: I2C pull-up resistors
  - **Location**: Near sensor connectors

#### Capacitors (Various Packages)

##### 0603 Package Capacitors
- **C2, C3**: 100nF ±10% (Marking: "104")
  - **Function**: Bypass/decoupling capacitors
  - **Location**: Near ESP32 module
  
- **C5, C6**: 12pF ±5% (Marking: "120")
  - **Function**: Crystal load capacitors
  - **Location**: Adjacent to 32.768kHz crystal
  
- **C7, C8**: 100nF ±10% (Marking: "104") - **Bottom side**
  - **Function**: Additional decoupling
  - **Location**: Bottom side near power components

##### Larger Package Capacitors
- **C1**: 22µF ±20% (Package: 1206)
  - **Function**: Input filter capacitor
  - **Marking**: May show "22µF" or capacitance code
  - **Location**: Near power input
  
- **C4**: 10µF ±20% (Package: 0805)
  - **Function**: Output filter capacitor
  - **Location**: Near voltage regulator output

### Active Components

#### Q1 - 2N7002 MOSFET
- **Package**: SOT-23 (3-pin)
- **Marking**: "7002" or "A7W"
- **Orientation**: Gate/Source/Drain per PCB marking
- **Function**: Level shifting for programming interface

#### D1 - Schottky Diode
- **Package**: SOD-123
- **Marking**: Diode symbol or part number
- **Polarity**: Cathode band alignment critical
- **Function**: Reverse polarity protection

### Crystal
#### Y1 - 32.768kHz Crystal
- **Package**: Crystal-3215 (3.2 x 1.5mm)
- **Marking**: "32.768" or frequency marking
- **Function**: Real-time clock reference
- **Handling**: Fragile - avoid dropping or shock

### LEDs and Indicators

#### Status LEDs (0603 Package or 3mm Through-hole)
- **L1**: Power LED (typically red or green)
- **L2**: Status LED (typically blue)
- **L3**: WiFi LED (typically green)
- **L4**: Error LED (typically red)

**Polarity Critical**: 
- Anode (+) and Cathode (-) must match PCB markings
- For 0603: Look for green marking indicating cathode
- For 3mm: Longer lead is anode (+)

## Connector Identification and Placement

### Power Connectors

#### J1 - USB-C Connector
- **Type**: USB Type-C receptacle
- **Function**: Programming and power input
- **Mounting**: Surface mount with mechanical tabs
- **Orientation**: Connector opening faces edge of PCB

#### J5 - DC Power Jack
- **Type**: 2.1mm center-positive barrel jack
- **Function**: External power input (5-12V DC)
- **Mounting**: Through-hole with mechanical stability
- **Polarity**: Center pin positive, outer ring negative

### Data Connectors

#### J2 - Programming Header
- **Type**: 2.54mm (0.1") pitch 6-pin header
- **Function**: UART programming interface
- **Pin assignment** (left to right):
  1. 3V3 (Power output)
  2. GND (Ground)
  3. TX (Transmit from ESP32)
  4. RX (Receive to ESP32)
  5. RST (Reset input)
  6. GPIO0 (Boot mode select)

#### J3, J4 - I2C Sensor Connectors
- **Type**: JST-PH 2.0mm pitch 4-pin connectors
- **Function**: I2C sensor interface
- **Pin assignment** (standard I2C pinout):
  1. VCC (3.3V power)
  2. GND (Ground)
  3. SDA (I2C data)
  4. SCL (I2C clock)

### Switches

#### SW1 - Reset Switch
- **Type**: 6mm tactile switch
- **Function**: Manual reset of ESP32
- **Mounting**: Through-hole, 4-pin for stability

#### SW2 - Boot Switch
- **Type**: 6mm tactile switch
- **Function**: Programming mode entry
- **Mounting**: Through-hole, 4-pin for stability

### Test Points

#### TP1-TP7 - Test Points
- **Type**: 1mm test points or small pads
- **Function**: Access to critical signals for debugging
- **Assignments**:
  - TP1: 3.3V power rail
  - TP2: Ground reference
  - TP3: 5V power rail (if present)
  - TP4: UART TX signal
  - TP5: UART RX signal
  - TP6: Reset signal
  - TP7: GPIO0 (boot mode)

## Placement Guidelines

### General Rules
1. **Orient components** according to PCB silkscreen markings
2. **Check polarity** for all polarized components (diodes, LEDs, electrolytic capacitors)
3. **Verify pin 1** orientation for all ICs
4. **Ensure clearances** around tall components
5. **Consider rework access** when placing adjacent components

### Critical Alignments

#### ESP32 Module (U1)
- Pin 1 corner must align with PCB pin 1 indicator
- Module must be fully seated with no gaps
- Antenna area (marked on PCB) must remain clear
- All shield pins must make contact with ground pads

#### Voltage Regulator (U2)
- SOT-223 tab must align with thermal pad
- Pin 1 (input) faces power input connectors
- Good thermal contact essential for heat dissipation

#### Crystal (Y1)
- Orientation not critical (crystal is symmetric)
- Ensure good pad contact for electrical connection
- Place load capacitors (C5, C6) as close as possible

### Component Height Considerations

Assembly order should consider component heights:

1. **Lowest**: SMT passives (0603, 0805, 1206)
2. **Medium**: SOT-23, SOD-123, crystal packages
3. **Higher**: ESP32 module, voltage regulator
4. **Highest**: Through-hole connectors and switches

## Visual Inspection Checklist

After component placement, verify:

### SMT Components
- [ ] All components present and correctly oriented
- [ ] No tombstoned components (one end lifted)
- [ ] Components centered on pads
- [ ] No damaged components or lifted pads
- [ ] Proper spacing maintained

### Through-Hole Components
- [ ] Components fully inserted and seated
- [ ] Correct orientation for polarized components
- [ ] No bent or damaged leads
- [ ] Mechanical stability before soldering

### Critical Components
- [ ] ESP32 pin 1 alignment verified
- [ ] Voltage regulator thermal pad contact
- [ ] Crystal and load capacitor proximity
- [ ] LED polarity correct
- [ ] Connector pin assignments verified

## Common Placement Errors

### Most Common Issues
1. **Reversed polarized components** (LEDs, diodes)
2. **IC orientation errors** (especially ESP32 module)
3. **Component value mix-ups** (resistors with similar markings)
4. **Missing components** (small passives easily lost)
5. **Incorrect connector orientation**

### Prevention Strategies
- **Double-check** component markings against BOM
- **Use magnification** for small component markings
- **Organize components** in clearly labeled containers
- **Verify orientations** before and after placement
- **Take photos** at each stage for reference

## Reference Documentation

- **PCB Assembly Drawing**: `visual_aids/pcb_layout_diagrams/`
- **Component Specifications**: `../bom/ESP_SensorHub_v1.0_BOM.csv`
- **Schematic Reference**: Available in design files
- **Soldering Procedures**: `soldering_guide.md`

---

**Important**: This placement guide should be used in conjunction with the step-by-step assembly guide and soldering procedures for complete assembly instructions.
