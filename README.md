# Arduino Uno based MAX6675 Thermocouple Temperature Controller with Relay 5V

## Overview

This project Real-Time monitor the **MAX6675 Thermocouple Amplifier Module** and a **K-Type Thermocouple Sensor** to measure temperature and automatically control a relay when a temperature threshold is reached.

**Funtionality:
**

* Turns the relay **ON** when temperature is equal to or above the configured threshold.
* Turns the relay **OFF** when temperature falls below the threshold.
* Displays temperature readings in both **Celsius (°C)** and **Fahrenheit (°F)** through the Serial Monitor.
* Detects thermocouple connection errors and safely turns the relay OFF.

---
## Hardware Required

| Component                                  | Quantity    |
| ------------------------------------------ | ----------- |
| Arduino Compatible Board (Uno, Nano, etc.) | 1           |
| MAX6675 Thermocouple Module                | 1           |
| K-Type Thermocouple Probe                  | 1           |
| Relay Module (5V or 3.3V depending on MCU) | 1           |
| Jumper Wires                               | As Required |
| Power Supply                               | 1 or use Arduino Uno as Power Source|

---

## Pin Connections

### MAX6675 Connections

| MAX6675 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 3.3V          |
| GND         | GND         |
| SCK         | D9          |
| CS          | D6          |
| SO          | D7          |

### Relay Connections

| Relay Pin | Arduino Pin |
| --------- | ----------- |
| IN        | D8          |
| VCC       | 5V          |
| GND       | GND         |

---
<img width="520" height="248" alt="image" src="https://github.com/user-attachments/assets/f319c9c3-14f9-420a-b6ee-92b33cf4d800" />

<img width="376" height="293" alt="image" src="https://github.com/user-attachments/assets/378a28c1-6be9-4393-9c6e-316bc51743c7" />

## System Operation

### Temperature Measurement

The MAX6675 converts the thermocouple voltage into a digital temperature reading.

The Arduino reads:

* Temperature in Celsius
* Temperature in Fahrenheit

every second.

Example:

```text
10.000 --> Temp: 27.50 °C | 81.50 °F
10.000 --> Relay: OFF
```

---

### Relay Control Logic

The temperature threshold is defined in the code:

```cpp
#define TEMP_THRESHOLD 30.0
```

#### Relay OFF Condition

```text
Temperature < 30°C
```

Relay remains OFF.

Example:

```text
Temp = 28°C
Relay = OFF
```

---

#### Relay ON Condition

```text
Temperature ≥ 30°C
```

Relay turns ON.

Example:

```text
Temp = 32°C
Relay = ON
```

---

## Thermocouple Error Detection

If the thermocouple becomes disconnected or communication fails:

```text
Thermocouple ERROR! Check wiring.
```

The relay is immediately turned OFF for safety.

---

## Software Setup

### Required Library

Install the MAX6675 library through Arduino IDE Library Manager. 
or download on github 

https://github.com/adafruit/MAX6675-library

Common library:

```text
max6675
```

---

### Upload Steps

1. Open Arduino IDE.
2. Install the MAX6675 library.
3. Connect your Arduino board.
4. Open the project sketch.
5. Select the correct board and COM port.
6. Click **Upload**.
7. Open **Serial Monitor**.
8. Set baud rate to:

```text
9600
```

---

## Adjusting Temperature Threshold

Modify the following line:

```cpp
#define TEMP_THRESHOLD 30.0
```

Examples:

```cpp
#define TEMP_THRESHOLD 50.0
```

Relay turns ON at 50°C.

```cpp
#define TEMP_THRESHOLD 100.0
```

Relay turns ON at 100°C.

---

## Serial Output Example

```text
MAX6675 + Relay Ready
Threshold set to: 30.0 °C

1.000 --> Temp: 25.25 °C | 77.45 °F
1.000 --> Relay: OFF

2.000 --> Temp: 29.75 °C | 85.55 °F
2.000 --> Relay: OFF

3.000 --> Temp: 31.50 °C | 88.70 °F
3.000 --> Relay: ON
```

---
