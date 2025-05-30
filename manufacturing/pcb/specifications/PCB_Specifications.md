# ESP Sensor Hub PCB Specifications

## Board Overview
- **Board Name**: ESP Sensor Hub v1.0
- **Dimensions**: 65mm x 40mm (approximate credit card size)
- **Layer Count**: 2 layers (Top and Bottom copper)
- **Board Thickness**: 1.6mm (standard)
- **Copper Weight**: 1oz (35µm) on both layers
- **Material**: FR4 standard PCB substrate
- **Surface Finish**: HASL (Hot Air Solder Leveling) or ENIG (Electroless Nickel Immersion Gold)

## Design Rules
- **Minimum Trace Width**: 0.1mm (4 mils)
- **Minimum Via Size**: 0.2mm (8 mils) drill, 0.45mm (18 mils) pad
- **Minimum Clearance**: 0.1mm (4 mils)
- **Minimum Annular Ring**: 0.05mm (2 mils)
- **Solder Mask**: Green (standard), other colors available
- **Silkscreen**: White on top, none on bottom

## Power Requirements
- **Input Voltage**: 3.3V - 12V DC (via onboard regulator)
- **Current Consumption**: 
  - Active: 120-260mA (ESP32) / 80-170mA (ESP8266)
  - Sleep: 0.01-0.06mA (ESP32) / 0.02-0.05mA (ESP8266)
- **Power Connector**: USB-C for programming/power, 2.1mm barrel jack for external power

## Component Placement
- **Top Side**: ESP32/ESP8266 module, sensors, status LEDs, programming header
- **Bottom Side**: Power management, supporting passives, optional components
- **Keep-out Areas**: 2mm from board edges, antenna area clear of copper

## Connector Specifications
- **Programming**: 6-pin 0.1" header (compatible with FTDI/CP2102)
- **I2C Sensors**: JST-PH 2.0mm 4-pin connectors
- **GPIO Expansion**: 0.1" pin headers
- **Power Input**: USB-C and 2.1mm barrel jack

## Manufacturing Tolerances
- **Hole Tolerance**: ±0.1mm
- **Board Dimensions**: ±0.15mm
- **Component Placement**: ±0.05mm for fine-pitch components

## Testing Points
- **Power Rails**: 3.3V, 5V, GND test points
- **Programming**: TX, RX, RST, GPIO0 test points
- **I2C Bus**: SDA, SCL test points
- **Status**: LED test points for troubleshooting

## Environmental Specifications
- **Operating Temperature**: -20°C to +70°C
- **Storage Temperature**: -40°C to +85°C
- **Humidity**: 5% to 95% non-condensing
- **Vibration**: 10G (per IEC 60068-2-6)

## Regulatory Compliance
- **RoHS**: Compliant (lead-free)
- **REACH**: Compliant
- **UL94**: V-0 flame rating (FR4 material)
- **IPC Standards**: IPC-2221, IPC-2222 for design rules

## Assembly Notes
- **Component Side**: Top side preferred for hand assembly
- **Paste Stencil**: 0.12mm (5 mils) thickness for 0402 components
- **Reflow Profile**: Lead-free SAC305 compatible
- **Wave Soldering**: Through-hole components only

## Panelization
- **Panel Size**: 100mm x 80mm (4 boards per panel)
- **Mouse Bites**: 0.5mm diameter, 0.8mm spacing
- **Fiducials**: 3 per panel, 1mm copper circles
- **Tooling Holes**: 2.5mm diameter in corners

## Quality Standards
- **IPC Class**: Class 2 (general electronic products)
- **AOI Testing**: Automated Optical Inspection recommended
- **ICT Testing**: In-Circuit Test points provided
- **Functional Test**: Programming and sensor validation required

## Cost Optimization
- **2-layer design** minimizes cost while meeting requirements
- **Standard components** (0402, 0603, SOIC) for automated assembly
- **Common materials** (FR4, HASL) for broad manufacturer support
- **Panelized production** for volume efficiency

## Manufacturer Compatibility
This design is compatible with:
- **JLCPCB**: Standard 2-layer service
- **PCBWay**: Standard PCB manufacturing
- **OSH Park**: Prototype quantities
- **Advanced Circuits**: US domestic manufacturing
- **Sunstone Circuits**: Quick-turn prototyping
