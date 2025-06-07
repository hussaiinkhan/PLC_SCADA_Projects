# 🧱 Box Sorting System using Ladder Logic (PLC)

This project is a complete **industrial simulation** of a PLC-based automated box sorting system, implemented entirely in **Ladder Logic (LD)** using OpenPLC. It demonstrates key skills in **PLC programming**, **sensor-based logic**, **conveyor automation**, and **industrial counting and alarm systems**—without using an HMI or SCADA interface.

---

## 🎯 Objective

The objective of this project is to simulate a **smart, sensor-based box sorting system** that can:

- Automatically classify boxes based on size
- Trigger conveyors to route boxes accordingly
- Count each type of box
- Raise alarms when a set threshold is reached

The project uses **pure ladder logic** to replicate how physical sensors and actuators behave in a factory-like environment. All logic, control, and visualization are handled programmatically using OpenPLC, showcasing strong fundamentals in PLC system design.

---

## 🛠️ Tools & Technologies

- **Programming Language:** Ladder Logic (LD)
- **PLC Platform:** OpenPLC (Web Editor)
- **Hardware Used:** Virtual PLC Simulation (No physical hardware or HMI)
- **Logic Elements:** Timers, Counters, Comparators, Relays

---

## 🔧 System Description

The system mimics a **box sorting conveyor line** that classifies boxes into small, medium, and large sizes based on simulated sensor inputs. Based on box size, each is routed to a dedicated conveyor (left, middle, or right). It keeps track of how many boxes of each type have been sorted, and activates an alarm when 15 boxes of any type are processed.

### 🎛 Control Logic Flow:

1. **Start/Stop Controls**:
   - Pressing the `Start` button energizes the main conveyor (`main_conveyer`).
   - `Stop` halts the entire operation immediately.

2. **Box Simulation using Sensors**:
   - The `pulse` signal initiates the timing logic, activating virtual sensors (`sensor1`, `sensor2`, `sensor3`) after defined intervals.
   - Sensor logic:
     - **Small Box:** Only `sensor1` triggers
     - **Medium Box:** `sensor1` + `sensor2` trigger
     - **Large Box:** All three sensors trigger

3. **Conveyor Routing**:
   - **Small Box →** `left_conveyer` activated
   - **Medium Box →** `middle_conveyer` activated
   - **Large Box →** `right_conveyer` activated

4. **Counting and Alarms**:
   - Each box type is counted using separate integer counters:
     - `small_boxes`, `middle_boxes`, `large_boxes`
   - When the count of any type reaches **15**, its corresponding alarm is triggered:
     - `small_boxes_alarm`, `middle_boxes_alarm`, `large_boxes_alarm`

5. **Reset Logic**:
   - Pressing the `reset` button resets all counters and alarms.

---

## 🔘 Tags Used

### Boolean Tags:

| Tag Name             | Purpose                              |
|----------------------|--------------------------------------|
| `start`              | Starts the main conveyor             |
| `stop`               | Stops the main conveyor              |
| `pulse`              | Triggers periodic sensor activation  |
| `main_conveyer`      | Master conveyor for box movement     |
| `left_conveyer`      | Moves small boxes to the left        |
| `middle_conveyer`    | Routes medium boxes to the middle    |
| `right_conveyer`     | Routes large boxes to the right      |
| `reset`              | Resets all counters and alarms       |
| `small_boxes_alarm`  | Alarm for 15 small boxes             |
| `middle_boxes_alarm` | Alarm for 15 medium boxes            |
| `large_boxes_alarm`  | Alarm for 15 large boxes             |

### Integer Tags:

| Tag Name         | Description                       |
|------------------|-----------------------------------|
| `small_boxes`    | Number of small boxes sorted      |
| `middle_boxes`   | Number of medium boxes sorted     |
| `large_boxes`    | Number of large boxes sorted      |

---

## ⏱ Timers & Simulation Logic

- **On-delay timers** simulate time-based triggering of sensors, as if boxes are arriving on the main conveyor at regular intervals.
- All conveyor switching logic is based on evaluating which combination of sensors is triggered.

---

## 📸 Screenshots

> _(Add ladder diagram screenshots, tag viewer images, or simulation screen captures)_

---

## 📦 Real-World Applications

This logic mirrors real-life industrial use cases such as:

- Package sorting systems in logistics and warehouses
- Material handling automation in manufacturing
- Quality control sorting lines based on dimensions

---

## 🧠 Key Skills Demonstrated

- Advanced Ladder Logic implementation
- Use of timers, counters, and alarms in automation
- Sensor simulation for industrial automation
- End-to-end logic handling without external HMI/SCADA
- Tag-based control, state machines, and logic sequencing

---


