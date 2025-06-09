# ⚙️ Motor Speed Monitoring & Analysis – Ignition SCADA + MySQL

This project demonstrates a **real-time SCADA system** built using **Ignition SCADA** to monitor, store, and analyze **motor speed (RPM)** with a **MySQL database** backend. The system provides dynamic updates, visualization, and analytical insights through charts and tables.

---

## 📋 Project Overview

- **Motor Speed Range:** 0 to 100 RPM
- **Speed is stored** in a MySQL database along with a timestamp each time it is changed.
- The system fetches **real-time and historical speed data** to calculate:
  - Current speed
  - Average speed
  - Minimum speed with timestamp
  - Maximum speed with timestamp
- Data is visualized through:
  - Easy chart (time-based trends)
  - Pie chart (speed distribution)
  - Bar chart (comparative analysis)
  - Data Table (for detailed records)

---

## ⚙️ Functional Flow

1. **Speed Input**  
   Operator can vary the motor speed using a slider/input (0–100 RPM).  

2. **Data Logging**  
   On every change:
   - The new speed is logged into a **MySQL database**
   - Timestamp is recorded for historical tracking

3. **Data Retrieval & Analysis**
   - Data is queried from MySQL using named queries or scripting
   - System calculates:
     - Current Speed
     - Average RPM
     - Minimum RPM (with timestamp)
     - Maximum RPM (with timestamp)

4. **Visualization**
   - **Easy Chart** shows real-time trends of motor speed
   - **Pie Chart** shows distribution (e.g., time spent in each speed range)
   - **Bar Chart** shows comparative speeds
   - **Table** displays exact data with timestamps

5. **Dynamic Interface**
   - All components update in real-time when speed changes
   - Useful for demo and operator visualization

---

## 🛠️ Technologies Used

- **Ignition SCADA** (Inductive Automation)
- **MySQL Database**
- **Named Queries**
- **Vision Module / Perspective Module**
- **Python Scripting**
- **Charting Components**: Easy Chart, Bar Chart, Pie Chart, Table

---

## 🖥️ Screenshots & Demo

## SCADA SCREEN DESIGN

<img width="830" alt="Screenshot 2025-06-09 at 11 09 52 PM" src="https://github.com/user-attachments/assets/1c1eb722-b0d2-4dba-a28d-1a304bb82481" />

## DEMO VIDEO

https://github.com/user-attachments/assets/4d43f14e-37cc-4a8d-828e-ec9597d8827c


---

## 🧮 Example Calculated Output

| Metric           | Value    | Timestamp         |
|------------------|----------|-------------------|
| Current Speed    | 68 RPM   | 2025-06-07 14:21  |
| Average Speed    | 55 RPM   | N/A               |
| Minimum Speed    | 12 RPM   | 2025-06-07 13:45  |
| Maximum Speed    | 95 RPM   | 2025-06-07 14:10  |

---
