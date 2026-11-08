
# Power System

## 1. Overview

The refrigerator prototype supports two power-source options:

1. AC mains through an AC-to-DC switched-mode power supply (SMPS).
2. Battery operation.

The selection between these power sources is performed manually.

## 2. AC Power Operation

The AC power input is supplied from a 220 V AC source.

An AC-to-DC SMPS converts the input into a 12 V DC output for the system's compatible loads.

The exact SMPS model, output-current rating, and power rating should be added after verification.

## 3. Battery Operation

The refrigerator can also operate using a battery as an alternative power source.

The battery provides an alternative to the AC-powered SMPS. The available battery voltage, capacity, chemistry, and operating duration have not yet been documented.

## 4. Power-Source Selection

The user manually selects between AC-powered and battery operation.

The system should not be described as having automatic power-source switching.

## 5. Important Electrical Specifications

The following information should be added when verified:

| Parameter | Specification |
|---|---|
| AC input | 220 V AC |
| SMPS output | 12 V DC |
| SMPS output current | To be verified |
| SMPS rated power | To be verified |
| Battery voltage | To be verified |
| Battery capacity | To be verified |
| Peltier module rating | To be verified |
| Fan voltage and current | To be verified |

## 6. Safety Considerations

- Mains-voltage wiring must be properly insulated and enclosed.
- The power supply must be appropriately rated for the connected loads.
- The Peltier module's hot side requires adequate heat dissipation.
- Battery connections must use suitable protection and wiring.
- The AC and battery selection mechanism must prevent unsafe connections between the two sources.

## 7. Further Improvements

Potential improvements include:

- Documenting power consumption under different operating conditions.
- Measuring battery operating time.
- Evaluating the efficiency of the cooling system.
- Investigating automatic power-source switching, if appropriate for a future version.
