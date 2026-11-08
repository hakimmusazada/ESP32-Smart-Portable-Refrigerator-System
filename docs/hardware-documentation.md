
# Hardware Documentation

## 1. Main Controller

The project uses an ESP32 development board as its central control unit. It coordinates environmental monitoring, door detection, LCD updates, and the door-open warning function.

## 2. Environmental Monitoring

A temperature and humidity sensor is installed to monitor the internal refrigerator environment.

The measured values are presented on an LCD, providing the user with a direct interface for observing the operating conditions.

The exact sensor model and communication interface should be specified after verification from the original hardware or source code.

## 3. Door Detection and Alert Mechanism

A magnetic sensor is used to detect whether the refrigerator door is open or closed.

The controller monitors the door state and activates a buzzer if the door remains open for longer than the configured threshold.

The default threshold described for this prototype is 20 seconds. The alert timing is adjustable.

## 4. Thermoelectric Cooling Assembly

The cooling system is based on a Peltier thermoelectric module.

The assembly includes two heat-transfer sections:

- **Hot side:** Connected to a larger external radiator to dissipate heat outside the refrigerator enclosure.
- **Cold side:** Connected to a smaller internal radiator to transfer cooling into the refrigerator compartment.

An additional fan is installed inside the refrigerator to circulate cooled air throughout the compartment.

Proper heat dissipation from the hot side is important for the cooling system to operate effectively.

## 5. Mechanical Construction

The refrigerator has a physical enclosure containing the cooling assembly.

The door is connected to the main body through a hinge mechanism. A magnetic door mechanism helps the door close securely.

The mechanical design also accommodates the internal and external cooling assemblies.

## 6. Design Files

The project repository is intended to include the available original design materials:

- ESP32 firmware source code
- Circuit schematic
- 3D model files (STL)
- Rendered design images
- Project photographs

These files should be added in their original formats whenever possible.

## 7. Verification Notes

Component models, dimensions, wiring connections, and electrical ratings should be documented from the original design files or verified hardware.

Unverified specifications should not be treated as confirmed design values.
