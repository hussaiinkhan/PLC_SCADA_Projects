# 🛢️ Tank Level Monitoring System – Ignition SCADA

This project simulates a **tank level monitoring system** built using **Ignition SCADA** by Inductive Automation. It includes automatic control of a pump and valve, level-based alarms, and sensor-based monitoring for industrial process management.

---

## 📋 Project Overview

The system is designed to:
- Automatically **fill** the tank using a **pump** when it is empty.
- Automatically **drain** the tank using a **valve** when it is full.
- Use **three level sensors** (low, mid, high) for intermediate monitoring.
- Raise **alarms** when the tank reaches specific level thresholds.
- Display **alarm status** in a dynamic and user-friendly alarm table.

---

## ⚙️ Functional Logic

### 1. **Tank Control Loop**

- When **tank level = 0**:
  - **Pump turns ON**
  - **Fills** the tank until level reaches **100**
  - Then **Pump turns OFF**

- When **tank level = 100**:
  - **Valve turns ON**
  - **Drains** the tank until level returns to **0**
  - Then **Valve turns OFF**

This loop runs continuously, simulating real-world tank fill/drain cycles.

---

### 2. **Sensor Integration**

| Sensor             | Trigger Level | Status |
|--------------------|---------------|--------|
| Low Level Sensor   | 15            | ON     |
| Mid Level Sensor   | 50            | ON     |
| High Level Sensor  | 90            | ON     |

These sensors help in identifying and displaying the tank’s current fill level with real-time status updates.

---

### 3. **Alarming System**

- **Low Level Alarm**: Triggered when level = 15
- **Mid Level Alarm**: Triggered when level = 50
- **High Level Alarm**: Triggered when level = 90

All alarms are displayed in an **Alarm Status Table** in the SCADA interface, providing operators with immediate feedback and historical logs for diagnostics.

---

## 🖥️ Technologies Used

- **Ignition SCADA** (by Inductive Automation)
- **Tag-based automation**
- **Expression bindings & scripting**
- **Alarm configuration**
- **HMI Design (Graphical Tank, Pump, Valve, Sensors)**

---

## 📷 Screenshots

## Project Structure

<img width="839" alt="Screenshot 2025-06-09 at 10 52 09 PM" src="https://github.com/user-attachments/assets/652aaa2b-1347-4b27-bb64-04558c54e041" />

## Demo Video


https://github.com/user-attachments/assets/74a8b4a3-669b-4e95-9460-9074b53d2ff8


---
