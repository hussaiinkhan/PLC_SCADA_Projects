# 🛗 5-Floor Elevator System (PLC Automation – Ladder Logic)

This project presents a simulation of a **fully automated elevator system** using **Ladder Logic (LD)** in OpenPLC. The elevator logic mimics a real-world 5-level building (Ground to Fifth floor), enabling automated vertical motion, floor tracking, and door control—all without the use of HMI/SCADA systems.

It demonstrates advanced PLC logic skills such as **comparators**, **counters**, **directional control**, and **event-based decision making** through real-time integer comparison and Boolean logic.

---

## 🎯 Objective

Design and implement an intelligent elevator system that:

- Moves up or down to a requested floor
- Opens the elevator door upon arrival
- Tracks the elevator’s current and target floors using integer tags
- Handles motion through directional logic and counter-based floor tracking

---

## 🛠 Tools & Technologies

- **Programming Language:** Ladder Logic (LD)
- **PLC Platform:** OpenPLC (Web Editor)
- **Simulation Type:** Logic-only (No HMI/SCADA)
- **Key Components:** Comparators, Up/Down Counters, Timers, Relays

---

## 📦 System Overview

The elevator logic works based on two integer values:

- `CurrentFloor` – the elevator's present floor (0–5)
- `TargetFloor` – the floor selected by the user

When a button for any floor is pressed, the system:

1. Sets the `TargetFloor` equal to the pressed floor’s number.
2. Compares `CurrentFloor` and `TargetFloor`.
3. If `CurrentFloor < TargetFloor`, the elevator:
   - Moves **upward**
   - Increments `CurrentFloor` using an **Up Counter**
   - Stops once `CurrentFloor == TargetFloor`, and opens the door

4. If `CurrentFloor > TargetFloor`, the elevator:
   - Moves **downward**
   - Decrements `CurrentFloor` using a **Down Counter**
   - Stops once `CurrentFloor == TargetFloor`, and opens the door

5. If `CurrentFloor == TargetFloor` from the start:
   - No movement occurs
   - Only the **door opens**

---

## 🧾 Boolean Tags (All Local)

| Tag Name         | Purpose                                      |
|------------------|----------------------------------------------|
| `ElevatorUp`     | Controls elevator motion upward              |
| `ElevatorDown`   | Controls elevator motion downward            |
| `Elevator`       | Main status of elevator (active/inactive)    |
| `ElevatorOn`     | Turns on elevator motor logic                |
| `ElevatorOff`    | Turns off elevator                           |
| `Door`           | Door status control                          |
| `DoorOpen`       | Opens the elevator door                      |
| `Pulse`          | Clock or signal pulse for timing logic       |
| `FloorReached`   | Confirms when destination floor is reached   |
| `GroundFloor`    | Button press for Ground Floor (0)            |
| `FirstFloor`     | Button press for Floor 1                     |
| `SecondFloor`    | Button press for Floor 2                     |
| `ThirdFloor`     | Button press for Floor 3                     |
| `FourthFloor`    | Button press for Floor 4                     |
| `FifthFloor`     | Button press for Floor 5                     |

---

## 🔢 Integer Tags

| Tag Name       | Description                                  |
|----------------|----------------------------------------------|
| `CurrentFloor` | Holds the current floor of the elevator       |
| `TargetFloor`  | Stores the floor requested by the user        |

---

## 🔁 Logic Flow

### 1. **Floor Selection**
When a user presses a floor button, the corresponding logic sets the `TargetFloor` to that floor’s number (e.g., pressing ThirdFloor sets `TargetFloor = 3`).

### 2. **Direction Decision**
Using comparator logic:
- If `CurrentFloor < TargetFloor`: Set `ElevatorUp = TRUE`
- If `CurrentFloor > TargetFloor`: Set `ElevatorDown = TRUE`

### 3. **Motion Simulation**
- While moving, the elevator’s `CurrentFloor` is **incremented** or **decremented** based on direction using an up-down counter.
- Motion continues until `CurrentFloor == TargetFloor`.

### 4. **Arrival & Door Control**
- Once the destination is reached:
  - Set `ElevatorUp` / `ElevatorDown` to `FALSE`
  - Set `ElevatorOff = TRUE`
  - Set `DoorOpen = TRUE`

---

## 📸 Screenshots

> _(Insert images of ladder logic rungs and tag values during simulation)_

---

## 💡 Real-World Applications

- Office and residential building elevators
- Hospital or mall lift systems
- Industrial platform lifts or dumbwaiters

---

## ✅ Key Concepts Demonstrated

- Multi-floor logic using integer comparison
- Floor tracking with up/down counters
- Directional motion automation
- Sequential control logic (Move → Stop → Open Door)
- Ladder Logic proficiency in PLC-based motion systems

