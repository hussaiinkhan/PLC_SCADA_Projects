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

### PLC logic for floor selection using MOV function block
<img width="1111" alt="Screenshot 2025-06-07 at 4 38 36 PM" src="https://github.com/user-attachments/assets/0ceca25e-f7ac-4b25-8ff2-c605378c3e94" />

### PLC Logic for comparing the current floor with target floor and deciding the elevator's required action using comparators
<img width="1131" alt="Screenshot 2025-06-07 at 4 38 56 PM" src="https://github.com/user-attachments/assets/0e1fc897-b31d-4321-b719-050c3d25b66b" />

### PLC Logic for increasing or decreasing the current floor value based on elevator action using function blocks and up-down counter block
<img width="1101" alt="Screenshot 2025-06-07 at 4 39 53 PM" src="https://github.com/user-attachments/assets/139a6f3e-9fb8-41ec-a4b1-b5c514b1e10d" />

### Demo Video (First fifth floor is pressed to move the elevator up and then ground floor to move the elevator down)
https://github.com/user-attachments/assets/9f006888-8491-42cc-a187-605fc8e7739c


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

