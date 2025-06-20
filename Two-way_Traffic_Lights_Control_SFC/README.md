# 🚦 Two-Way Traffic Light Control System with Pedestrian Stop – SFC Implementation

This project implements a **two-way traffic light control system** using **Sequential Function Chart (SFC)** programming in a PLC environment. It manages vehicle flow across a crossroad in both **East-West (EW)** and **North-South (NS)** directions, with a **pedestrian stop button** that safely interrupts the traffic cycle when activated.

---

## 📋 Project Description

The system is designed to:
- Alternate traffic lights between East-West and North-South directions.
- Maintain proper light sequencing (Green → Yellow → Red) using time-based transitions.
- Allow pedestrians to safely cross the road using a **Stop** button.
- Resume normal operation automatically after completing a pedestrian stop cycle.

---

## 🔧 How It Works

1. ### Initialization
   - The system starts at `Step0` when the `Start` input is triggered.
   - Transitions to `Step1` where the traffic light cycle begins.

2. ### Normal Traffic Flow
   The lights alternate as follows:

   - **East-West Direction:**
     - `Step4`: GreenEW ON for 5 seconds.
     - `Step5`: YellowEW ON for 2 seconds.
     - `Step6`: RedEW ON for 7 seconds.

   - **North-South Direction (in parallel):**
     - `Step7`: RedNS ON during East-West flow.
     - `Step8`: GreenNS ON for 5 seconds.
     - `Step9`: YellowNS ON for 2 seconds.

   - After both sequences complete, the logic loops back to `Step1`.

3. ### Pedestrian Stop Request
   - When the **Stop** button is pressed:
     - The logic jumps to `Step2`, activating **RedEW** and **RedNS** (halting all traffic).
     - Once this stop cycle completes, it returns to `Step1` and resumes normal flow.

---

## 🧠 Technologies Used

- **PLC Programming**
- **SFC (Sequential Function Chart) Language**
- **Timers:** `t#5s`, `t#2s`, `t#7s` for step durations
- **Ladder Logic integration** (for inputs like TrafficLights and Stop button)

---

## 📌 Features

- 🚗 Two-way traffic control (East-West and North-South)
- 🚶 Pedestrian stop functionality using a push button
- ⏱ Time-controlled light sequencing
- 🔁 Continuous operation with safe transitions
- 🔒 Prevents traffic conflicts and ensures pedestrian safety

---

## 📷 SFC Logic Diagram
<img width="1353" alt="Screenshot 2025-06-07 at 4 51 35 PM" src="https://github.com/user-attachments/assets/feae3ac6-3ff6-47c8-8b82-cc9ea27504d9" />

## Demo Video
https://github.com/user-attachments/assets/5fa3d7c9-4b83-4b3a-b42e-d2f4c3579bb4



