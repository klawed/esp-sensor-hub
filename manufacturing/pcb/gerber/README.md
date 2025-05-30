# Gerber Files for ESP Sensor Hub v1.0

## File List
This directory contains the complete Gerber file set for PCB manufacturing of the ESP Sensor Hub.

### Gerber Files
- **ESP_SensorHub_v1.0.GTL** - Top Copper Layer
- **ESP_SensorHub_v1.0.GBL** - Bottom Copper Layer  
- **ESP_SensorHub_v1.0.GTS** - Top Solder Mask
- **ESP_SensorHub_v1.0.GBS** - Bottom Solder Mask
- **ESP_SensorHub_v1.0.GTO** - Top Silkscreen
- **ESP_SensorHub_v1.0.GBO** - Bottom Silkscreen (if used)

### Drill Files
- **ESP_SensorHub_v1.0.DRL** - Excellon Drill File
- **ESP_SensorHub_v1.0-PTH.drl** - Plated Through Holes
- **ESP_SensorHub_v1.0-NPTH.drl** - Non-Plated Through Holes

### Assembly Files
- **ESP_SensorHub_v1.0_top_pos.csv** - Top Side Pick and Place
- **ESP_SensorHub_v1.0_bottom_pos.csv** - Bottom Side Pick and Place
- **ESP_SensorHub_v1.0_top_paste.gbr** - Top Paste Layer (for stencil)
- **ESP_SensorHub_v1.0_bottom_paste.gbr** - Bottom Paste Layer (if used)

### Documentation
- **ESP_SensorHub_v1.0_dimensions.pdf** - Board outline and dimensions
- **ESP_SensorHub_v1.0_assembly_top.pdf** - Top assembly drawing
- **ESP_SensorHub_v1.0_assembly_bottom.pdf** - Bottom assembly drawing

## Gerber File Specifications
- **Format**: RS-274X (Extended Gerber)
- **Units**: Millimeters
- **Coordinate Format**: 3.4 (3 integer digits, 4 decimal places)
- **Zero Suppression**: Leading zeros suppressed
- **Aperture Format**: Embedded apertures (no separate aperture list needed)

## Manufacturing Notes

### PCB Specifications
- **Board Size**: 65.0mm x 40.0mm
- **Board Thickness**: 1.6mm ±0.1mm
- **Layer Count**: 2 (Top + Bottom copper)
- **Copper Weight**: 1oz (35µm) both layers
- **Via Size**: 0.2mm drill, 0.45mm pad
- **Minimum Trace**: 0.1mm (4 mils)
- **Minimum Spacing**: 0.1mm (4 mils)

### Surface Finish Options
1. **HASL** (Hot Air Solder Leveling) - Standard, cost-effective
2. **ENIG** (Electroless Nickel Immersion Gold) - Better for fine-pitch components
3. **OSP** (Organic Solderability Preservative) - Lead-free alternative

### Solder Mask
- **Color**: Green (standard) - other colors available
- **Type**: LPI (Liquid Photo Imageable)
- **Thickness**: 0.01-0.03mm

### Silkscreen
- **Color**: White on green solder mask
- **Minimum Text Size**: 0.15mm (6 mils)
- **Minimum Line Width**: 0.1mm (4 mils)

## Quality Requirements
- **IPC Class**: Class 2 (General Electronic Products)
- **Electrical Test**: 100% continuity and isolation testing
- **Visual Inspection**: Per IPC-A-610 Class 2
- **Dimensional Tolerance**: ±0.1mm for holes, ±0.15mm for board outline

## Panelization
- **Panel Size**: 100mm x 80mm (accommodates 4 boards)
- **Spacing**: 2mm between boards
- **Mouse Bites**: 0.5mm diameter, 0.8mm spacing
- **Fiducials**: 1mm diameter copper circles (3 per panel)
- **Tooling Holes**: 2.5mm diameter in panel corners

## Stencil Requirements (for SMT Assembly)
- **Thickness**: 0.12mm (5 mils) for 0402 components
- **Material**: Stainless steel
- **Aperture Reduction**: 10% for fine-pitch components
- **Fiducials**: Required for automated assembly

## File Validation
Before manufacturing, validate Gerber files using:
- **Gerber Viewer**: KiCad, Altium Viewer, or online tools
- **DRC Check**: Design Rule Check against specifications
- **Drill Report**: Verify hole sizes and counts
- **Pick & Place**: Validate component positions

## Manufacturing Partners
These files are compatible with:
- **JLCPCB**: Upload ZIP file with all Gerbers
- **PCBWay**: Standard Gerber format supported
- **OSH Park**: 2-layer service compatible
- **Advanced Circuits**: US domestic manufacturer
- **Sunstone Circuits**: Quick-turn service

## Revision History
- **v1.0**: Initial release
  - 2-layer ESP32/ESP8266 compatible design
  - Standard component footprints
  - USB-C and barrel jack power options
  - I2C sensor interfaces
  - Status LEDs and test points

## Contact
For manufacturing questions or clarifications, please create an issue in the GitHub repository.
