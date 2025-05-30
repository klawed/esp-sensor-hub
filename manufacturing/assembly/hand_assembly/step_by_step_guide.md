# ESP Sensor Hub - Hand Assembly Guide

## Overview
This guide covers manual assembly of ESP Sensor Hub units (1-50 pieces). Perfect for prototyping, small production runs, and learning the assembly process.

## Before You Begin

### Required Skills
- Basic through-hole soldering
- SMT soldering (0603 and larger components)
- Ability to read component markings
- Steady hand for fine-pitch work

### Time Requirements
- **First unit**: 2-3 hours (learning curve)
- **Subsequent units**: 45-60 minutes each
- **Experienced assembler**: 30-40 minutes each

## Pre-Assembly Checklist

### Workspace Setup
- [ ] Clean, well-lit work area
- [ ] ESD mat and wrist strap connected
- [ ] Good ventilation for flux fumes
- [ ] Organized component storage
- [ ] All tools within reach

### Component Verification
- [ ] All components present (check against BOM)
- [ ] Component values verified
- [ ] No damaged or bent components
- [ ] Moisture-sensitive components properly stored

## Assembly Sequence

### Phase 1: SMT Components (Bottom Side First)
Assembly order is critical for SMT components to prevent tombstoning and ensure quality.

#### Step 1: Apply Solder Paste (Optional - for volume work)
If using solder paste instead of hand soldering:
- [ ] Align stencil to PCB bottom side
- [ ] Apply solder paste with squeegee
- [ ] Remove stencil carefully
- [ ] Inspect paste deposits for completeness

#### Step 2: Place Bottom-Side Components
**Order of placement (smallest to largest):**

1. **Passive Components (Bottom Side)**
   - [ ] **R6, R7** (4.7kΩ resistors) - 0603 package
   - [ ] **C7, C8** (100nF capacitors) - 0603 package
   
   **Placement Tips:**
   - Use tweezers with fine tips
   - Center components on pads
   - Ensure no tombstoning (one end lifted)
   - Check polarity if applicable

#### Step 3: Reflow Bottom Side
**Hot air reflow:**
- [ ] Preheat to 150°C
- [ ] Gradually increase to 240°C
- [ ] Hold for 20-30 seconds
- [ ] Cool gradually
- [ ] Inspect all joints

**Alternative: Hand soldering each component**

### Phase 2: SMT Components (Top Side)

#### Step 4: Place Top-Side Passive Components
**Assembly order (finest pitch first):**

1. **Crystal and Load Capacitors**
   - [ ] **Y1** (32.768kHz crystal) - Handle carefully, sensitive to shock
   - [ ] **C5, C6** (12pF capacitors) - Place close to crystal

2. **Small Passive Components**
   - [ ] **R1, R2** (10kΩ pull-up resistors) - 0603 package
   - [ ] **R3, R4, R5** (330Ω LED resistors) - 0603 package
   - [ ] **C2, C3** (100nF bypass capacitors) - 0603 package

3. **Larger Passive Components**
   - [ ] **C1** (22µF input capacitor) - 1206 package
   - [ ] **C4** (10µF output capacitor) - 0805 package
   - [ ] **D1** (Schottky diode) - SOD-123 package

#### Step 5: Place Active Components
**Critical components requiring care:**

1. **Voltage Regulator**
   - [ ] **U2** (AMS1117-3.3) - SOT-223 package
   - **Important**: Verify pin 1 orientation
   - **Thermal relief**: Ensure good thermal contact with ground plane

2. **Transistor**
   - [ ] **Q1** (2N7002 MOSFET) - SOT-23 package
   - **Critical**: Verify gate/source/drain orientation

#### Step 6: ESP32 Module Placement
- [ ] **U1** (ESP32-WROOM-32) - Most critical component
- **Special considerations:**
  - Verify pin 1 alignment with PCB marking
  - Ensure all pads make contact
  - Check for solder bridges on fine-pitch pins
  - Verify antenna area remains clear

### Phase 3: Through-Hole Components

#### Step 7: Connectors and Mechanical Components
**Install in order of increasing height:**

1. **Low-Profile Components**
   - [ ] **J2** (Programming header) - 2.54mm pitch
   - [ ] **TP1-TP7** (Test points) - If using socketed test points

2. **Switches**
   - [ ] **SW1** (Reset switch) - Tactile switch
   - [ ] **SW2** (Boot switch) - Tactile switch

3. **Sensor Connectors**
   - [ ] **J3, J4** (I2C sensor connectors) - JST-PH 4-pin
   - **Note**: Mount flush to PCB surface

4. **Power Connectors**
   - [ ] **J1** (USB-C connector) - Main power/programming
   - [ ] **J5** (DC barrel jack) - External power option

5. **Status LEDs**
   - [ ] **L1** (Power LED) - 0603 package or 3mm through-hole
   - [ ] **L2, L3, L4** (Status LEDs) - Match L1 type
   - **Important**: Verify polarity (cathode/anode orientation)

## Soldering Techniques

### SMT Soldering Best Practices

#### Equipment Settings
- **Soldering iron**: 315-330°C (600-625°F)
- **Tip**: Fine chisel or conical tip
- **Solder**: 0.6mm SAC305 (lead-free) or 63/37 leaded
- **Flux**: No-clean flux paste

#### SMT Soldering Steps
1. **Tack one corner** of component to hold in place
2. **Check alignment** before proceeding
3. **Solder remaining pins** one at a time
4. **Inspect joints** for proper wetting and no bridges
5. **Clean with isopropyl alcohol** if using rosin flux

#### Common SMT Issues and Solutions
- **Tombstoning**: Pre-tin one pad, place component, solder other end first
- **Solder bridges**: Use solder wick and flux to remove excess
- **Cold joints**: Increase temperature, ensure clean surfaces
- **Component drift**: Hold firmly while solder cools

### Through-Hole Soldering

#### Standard Technique
1. **Insert component** through holes
2. **Bend leads slightly** to hold in place
3. **Heat pad and lead** simultaneously
4. **Apply solder** to joint, not iron
5. **Remove solder**, then iron
6. **Trim excess leads** after cooling

#### Connector Soldering
- **Multiple pins**: Solder alternate pins to prevent stress
- **Large thermal mass**: Increase temperature 10-20°C
- **Mechanical stress**: Ensure good fillet formation

## Quality Control Checkpoints

### After Each Phase
- [ ] Visual inspection for proper component placement
- [ ] Check for solder bridges with magnification
- [ ] Verify all joints have proper wetting
- [ ] Test continuity of critical nets
- [ ] Check component orientations

### Detailed Inspection Points

#### SMT Component Checklist
- [ ] No tombstoned components
- [ ] Solder fillets visible on all joints
- [ ] No solder bridges between pins
- [ ] Components centered on pads
- [ ] Proper component orientations verified

#### Through-Hole Component Checklist
- [ ] Components fully seated against PCB
- [ ] Proper solder joint formation (volcano shape)
- [ ] No cold or disturbed joints
- [ ] Lead trimming complete and safe
- [ ] No mechanical stress on joints

### Electrical Testing
Perform these tests after assembly completion:
- [ ] Power supply voltage measurements
- [ ] Continuity testing of critical paths
- [ ] Basic functionality test (LED indicators)
- [ ] Programming interface verification

## Documentation and Traceability

### Assembly Records
For each unit, document:
- [ ] Assembly date and time
- [ ] Assembler identification
- [ ] Component lot numbers (if required)
- [ ] Any deviations or rework performed
- [ ] Quality control sign-off

### Digital Photography
Take photos for documentation:
- [ ] Before assembly (bare PCB)
- [ ] After SMT assembly (both sides)
- [ ] Final assembled unit
- [ ] Any special procedures or rework

## Common Assembly Issues

### Prevention Strategies
- **Component orientation errors**: Use assembly drawings and double-check
- **Solder bridges**: Use appropriate solder amount and clean tip
- **Cold joints**: Ensure proper temperature and clean surfaces
- **Component damage**: Handle with care, use proper ESD protection

### Rework Procedures
- **Component removal**: Use hot air or desoldering wick
- **Pad repair**: Clean thoroughly, re-tin if necessary
- **Replacement**: Follow original assembly procedures
- **Documentation**: Record all rework performed

## Time and Motion Optimization

### Efficiency Tips for Multiple Units
- **Batch similar operations**: Solder all resistors, then all capacitors
- **Pre-position components**: Organize on placement tray
- **Minimize tool changes**: Complete all operations with one tool before switching
- **Quality checks**: Inspect after each phase, not after completion

### Setup for Volume
- **Component dispensing**: Use pick-and-place friendly packaging
- **Fixture use**: Consider simple positioning fixtures for consistency
- **Workflow optimization**: Arrange workspace for left-to-right flow
- **Quality systems**: Implement checksheets and statistical sampling

---

**Next Steps**: After successful hand assembly, proceed to programming and testing procedures in the `testing/` directory.
