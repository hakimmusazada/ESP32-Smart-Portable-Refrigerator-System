
# Software Documentation

## 1. Overview

The refrigerator controller is implemented using an ESP32 development board and the Arduino framework.

The firmware handles three primary functions:

- Temperature and humidity monitoring
- LCD display updates
- Door-state monitoring with an audible warning

The program uses the Arduino `millis()` function to manage periodic operations without relying on long delays during the main control loop.

## 2. Required Libraries

| Library | Purpose |
|---|---|
| Wire.h | I2C communication |
| LiquidCrystal_I2C.h | Control of the I2C LCD |
| DHT.h | Communication with the DHT11 sensor |

## 3. Pin Configuration

| ESP32 GPIO | Connected Component | Function |
|---|---|---|
| GPIO 4 | DHT11 | Temperature and humidity sensor data |
| GPIO 2 | Magnetic sensor | Door-state detection |
| GPIO 15 | Buzzer | Audible door-open warning |
| GPIO 21 | LCD I2C SDA | I2C data |
| GPIO 22 | LCD I2C SCL | I2C clock |

The LCD is configured with I2C address `0x27` and a 16-column, 2-row display.

## 4. Firmware Operation

### 4.1 Initialization

During startup, the ESP32:

1. Configures the magnetic sensor pin as an input.
2. Configures the buzzer pin as an output.
3. Sets the buzzer to LOW.
4. Initializes I2C communication using GPIO 21 and GPIO 22.
5. Initializes the LCD and enables its backlight.
6. Initializes the DHT11 sensor.
7. Displays `System Ready` for two seconds.

### 4.2 Temperature and Humidity Monitoring

The DHT11 sensor is read every 2 seconds using the `millis()` timing mechanism.

The firmware retrieves:

- Relative humidity using `dht.readHumidity()`
- Temperature in Celsius using `dht.readTemperature()`

The measured values are displayed on the LCD.

If either sensor reading is invalid, the LCD displays:

- `Sensor Error`
- `Check DHT pin`

### 4.3 Door-State Detection

The magnetic sensor is monitored continuously in the main loop.

According to the firmware logic:

- HIGH indicates that the magnet is near and the door is closed.
- LOW indicates that the magnet is away and the door is open.

When the door is detected as open for the first time, the firmware records the current time using `millis()`.

### 4.4 Door-Open Alarm

The configured alarm delay is:

`alarmDelay = 20000` milliseconds.

Therefore, the buzzer activates after the door has remained open for approximately 20 seconds.

The buzzer remains active while the door is open after the threshold has been reached. It is turned off when the door is detected as closed.

The alarm delay can be adjusted by changing the `alarmDelay` value in the firmware.

## 5. Timing Mechanism

The firmware uses `millis()` to track elapsed time.

Two independent timing mechanisms are used:

| Operation | Configured Interval |
|---|---:|
| DHT11 sensor reading and LCD update | 2 seconds |
| Door-open alarm activation | 20 seconds |

This approach allows the door-monitoring logic and environmental monitoring logic to operate within the same main loop.

## 6. Current Firmware Scope

The provided firmware implements:

- DHT11 temperature and humidity monitoring
- LCD data display
- Magnetic door-state detection
- Configurable door-open alarm timing
- Buzzer activation and deactivation

The provided firmware does not contain the control logic for the Peltier module, cooling fans, battery management, or automatic power-source switching. These functions should not be attributed to this particular firmware unless they are implemented in another verified part of the project.

## 7. Potential Future Improvements

- Add sensor-reading validation and recovery handling.
- Add configurable alarm timing through a user interface.
- Introduce temperature-based cooling control, if not already implemented in separate hardware or firmware.
- Add data logging for temperature and humidity.
- Add low-battery monitoring if supported by the hardware.
- Improve input-state reliability through verified sensor wiring and suitable input configuration.
