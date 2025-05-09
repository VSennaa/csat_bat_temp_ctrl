# 🛰️ Cubesat Battery Temperature Control

A simple temperature control system for battery modules in a Cubesat, using the **LM335Z** temperature sensor and a **Peltier module** for heating.

---

## 🔧 Description

This project implements a basic proportional control system using the LM335Z sensor to monitor temperature and a Peltier module to heat the battery pack. An ESP32 microcontroller reads the temperature, calculates the control signal, and applies PWM to a MOSFET to adjust the heating power. The system maintains the temperature around a defined target (default: 40 °C, just for the test purposes).

The source code configures:

- **Analog input** to read the LM335 sensor.
- **PWM output** to drive a MOSFET connected to the Peltier.
- A **proportional control loop** with temperature feedback.
- **Serial output** for real-time monitoring of temperature and PWM duty.
- NT: The peltierlm and lm335z should be used in a ESP32. The peltieruno is to Arduino UNO.

> 🔍 The full code can be found in the file: `peltierlm.ino`. 

---

## ⚙️ How to Use

1. Connect the **LM335** sensor to an analog input (e.g., GPIO 34 on ESP32).
2. Connect a **PWM output** (e.g., GPIO 16) to a MOSFET gate that controls the Peltier module.
3. Power the system appropriately (Peltier modules can draw significant current).
4. Upload the code to the ESP32 using Arduino IDE or a compatible environment.
5. Open the Serial Monitor at **115200 baud** to view temperature and PWM data.

---

## 📫 Contact

- **Email**: [vsennamart@gmail.com](mailto:vsennamart@gmail.com)
