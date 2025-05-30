# ESP Sensor Hub v1.0 - Manufacturing Notes

## PCB Fabrication Order Instructions

### Quick Reference
- **Board Size**: 65.0 x 40.0 mm
- **Layers**: 2 (copper layers)
- **Thickness**: 1.6mm
- **Copper Weight**: 1oz
- **Surface Finish**: HASL or ENIG
- **Solder Mask**: Green
- **Silkscreen**: White

### File Validation Checklist
Before submitting for manufacturing, verify:

- [ ] **Gerber Files Present**:
  - ESP_SensorHub_v1.0.GTL (Top Copper)
  - ESP_SensorHub_v1.0.GBL (Bottom Copper)
  - ESP_SensorHub_v1.0.GTS (Top Solder Mask)
  - ESP_SensorHub_v1.0.GBS (Bottom Solder Mask)
  - ESP_SensorHub_v1.0.GTO (Top Silkscreen)

- [ ] **Drill Files Present**:
  - ESP_SensorHub_v1.0.DRL (All holes)

- [ ] **Assembly Files Present**:
  - ESP_SensorHub_v1.0_top_pos.csv (Pick & Place)

### Manufacturer Upload Instructions

#### JLCPCB
1. Create ZIP file with all Gerber and drill files
2. Upload to JLCPCB quote system
3. Verify board preview matches design
4. Select specifications:
   - PCB Thickness: 1.6mm
   - Copper Weight: 1oz
   - Surface Finish: HASL(with lead) or HASL(lead free)
   - Solder Mask Color: Green
   - Silkscreen Color: White

#### PCBWay
1. Create ZIP file with all Gerber files
2. Use online quote system
3. Specify 2-layer PCB
4. Confirm dimensions: 65x40mm
5. Select HASL or ENIG finish

#### OSH Park
1. Upload ZIP file or individual Gerber files
2. System auto-detects 2-layer board
3. Purple solder mask (OSH Park standard)
4. ENIG finish included

### Quality Control Points
- Verify board outline dimensions
- Check drill file hole count and sizes
- Confirm component footprints match library
- Review silkscreen text readability
- Validate solder mask openings

### Cost Optimization Tips
- Order in multiples of panel size (4 boards per 100x80mm panel)
- HASL finish is more economical than ENIG
- Standard green solder mask reduces cost
- Combine with other projects for volume discounts

### Lead Times
- **Standard PCB**: 5-7 business days
- **Express PCB**: 2-3 business days
- **Assembly Service**: +3-5 business days
- **Shipping**: Varies by location and method

### Design Validation
This PCB design has been validated for:
- Standard 2-layer manufacturing processes
- Hand soldering assembly
- Automated pick-and-place assembly
- Wave soldering (through-hole components)
- Reflow soldering (SMT components)

### Troubleshooting
Common issues and solutions:
- **File upload errors**: Ensure ZIP contains all required files
- **Dimension mismatch**: Verify Gerber units (mm vs inches)
- **Missing drill hits**: Check drill file format (Excellon)
- **Silkscreen errors**: Ensure text size meets manufacturer minimums

### Contact Information
For manufacturing questions, create an issue in the GitHub repository with:
- Manufacturer name
- Error message or issue description
- Screenshots of manufacturer feedback
- Files used for quote/order
