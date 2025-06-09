# 🚀 Industrial Automation Portfolio – PLC, SFC & SCADA Projects

Welcome to my **Industrial Automation Portfolio Repository**!  
This repository showcases a curated collection of hands-on **PLC**, **SFC**, and **SCADA (Ignition)** projects, each simulating real-world industrial systems and processes. From logic-based automation to database-integrated analytics — this portfolio highlights my skills across the full automation stack.

---

## 🛠️ Technologies Used

- 🟨 **PLC Programming** – Ladder Logic, Function Blocks
- 🔄 **Sequential Function Chart (SFC)**
- 💡 **Ignition SCADA** – by Inductive Automation
- 🗃️ **MySQL** – for data logging and analysis
- 📊 **Charts & Alarms** – Easy Chart, Bar, Pie, Alarm Tables

---

## 📂 Project Structure

### 🧠 PLC Projects

#### 📁 `01_Box_Sorting_Project`
A logic-driven PLC project designed in **Ladder Logic**, simulating an automated box sorting system based on size.  
- **Sensors** detect small, medium, and large boxes.
- **Conveyors** route boxes to the correct lane.
- **Counters** keep track of sorted items.
- **Alarms** activate when item count hits 15.

> 🔧 All logic implemented entirely in Ladder Logic — no HMI used.

#### 📁 `02_Elevator_Control_5_Floors`
A fully functional elevator system for 5 floors (including ground), developed using **Ladder Logic** and integer comparators.  
- Pressing any floor button updates the **target floor**.
- **Elevator movement** is controlled by comparing current and target floor.
- **Up/Down counters** simulate floor movement.
- **Door operations** activate upon arrival.

---

### 🧭 SFC Project

#### 📁 `03_Two_Way_Traffic_Lights_Control`
A road intersection system using **SFC (Sequential Function Chart)** logic to control traffic lights and pedestrian crossings.  
- Controls **Red, Yellow, Green lights** for two directions.
- A **pedestrian stop button** triggers safe light transitions.
- Ensures smooth traffic flow and safe pedestrian crossing.
- Fully visualized using Ignition's SFC module.

---

### 🖥️ SCADA Projects (Ignition)

#### 📁 `04_Tank_Level_Monitoring`
An Ignition SCADA project that **monitors and automates tank levels** with dynamic pump/valve control, sensor logic, and alarms.
- **Pump** starts at level 0, stops at 100.
- **Valve** drains water once full.
- **Sensors** (Low/Mid/High) activate at set levels.
- **Alarm table** visualizes warning thresholds.

> 🔁 Fully automated control cycle with visual indicators and real-time monitoring.

#### 📁 `05_Motor_Speed_Monitoring_And_Analysis`
An advanced SCADA system to **monitor, store, and analyze motor RPM (0–100)** using MySQL and dynamic visualizations.
- Speed changes are **logged with timestamps** to MySQL.
- Charts display:
  - Real-time RPM
  - **Average**, **Min**, **Max** RPM values
- Includes: **Easy Chart**, **Bar Chart**, **Pie Chart**, **Data Table**

> 📈 Ideal for analyzing motor behavior over time.

---

## 📽️ Demo Media

Each directory contains screenshots and videos demonstrating the real-time working of the system. This enhances the understanding of how industrial automation works across PLCs and SCADA environments.

---

## 🙋‍♂️ About Me

I’m an aspiring **Industrial Automation & SCADA Engineer**, passionate about building systems that simulate real industrial processes using the latest technologies. I love combining control logic with visualization and data analytics for smarter decision-making.

Feel free to connect with me on [LinkedIn](https://www.linkedin.com/in/hussainmehboob/) or reach out for freelance collaborations, internships, or projects. 

---

## 📄 License

This repository is open-source for educational and professional portfolio purposes. You're welcome to explore, fork, and learn!

---

**⭐ If this portfolio inspires you or showcases relevant skills, give it a star and share it with others!**
