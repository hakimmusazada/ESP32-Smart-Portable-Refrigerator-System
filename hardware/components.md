
# Hardware Components

## 1. Main Controller

| Component | Role |
|---|---|
| ESP32 development board | Main controller responsible for monitoring sensor data and controlling the refrigerator's functions |

## 2. Monitoring and Door Detection

| Component | Role |
|---|---|
| Temperature and humidity sensor | Measures the temperature and relative humidity inside the refrigerator |
| LCD display | Displays the measured temperature and humidity |
| Magnetic door sensor | Detects whether the refrigerator door is open or closed |
| Buzzer | Produces an audible warning when the door remains open beyond the configured time threshold |

## 3. Cooling and Air Circulation

| Component | Role |
|---|---|
| Peltier thermoelectric module | Provides thermoelectric cooling |
| External radiator / heatsink | Dissipates heat from the hot side of the thermoelectric cooling assembly |
| Internal radiator / heatsink | Transfers cooling from the cold side into the refrigerator's interior |
| Internal DC fan | Circulates cooled air throughout the refrigerator compartment |
| 12 V power supply | Supplies power to the cooling system and other compatible loads |

## 4. Power System

| Component | Role |
|---|---|
| AC-to-DC SMPS | Converts 220 V AC input into 12 V DC output |
| Battery | Provides an alternative power source |
| Power-source selection mechanism | Allows manual selection between AC supply and battery operation |

## 5. Mechanical Structure

| Component / Assembly | Role |
|---|---|
| Refrigerator enclosure | Houses the cooling system and stored items |
| Door and hinge assembly | Connects the door to the refrigerator body and enables opening and closing |
| Magnetic door mechanism | Helps the door close securely |

## Notes

- Exact sensor models, component part numbers, and electrical ratings should be added when verified from the original hardware or design files.
- The system supports AC and battery operation through manual power-source selection. Automatic source switching is not implemented.
- The Peltier module requires appropriate heat dissipation on its hot side for effective operation.

