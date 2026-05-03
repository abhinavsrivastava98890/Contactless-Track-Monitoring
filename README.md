[README.md](https://github.com/user-attachments/files/27316301/README.md)
# Contactless Track Monitoring System
A hardware prototype for contactless railway track monitoring.
# 🚂 Contactless Track Monitoring Robot

![Inverthon 2.0](https://img.shields.io/badge/Inverthon-2.0-blue)
![Team sDx Legends](https://img.shields.io/badge/Team-sDx%20Legends-green)
![Invertis University](https://img.shields.io/badge/Institute-Invertis%20University-orange)
![Category](https://img.shields.io/badge/Category-Hardware-red)

An autonomous contactless robot designed for real-time railway track crack detection and obstacle monitoring — no train stoppage required, instant audio-visual fault alerts, low-cost and deployable anywhere.

![Robot Overview](https://via.placeholder.com/800x400?text=Contactless+Track+Monitoring+Robot)

---

## 📋 Table of Contents

- [What This Project Does](#-what-this-project-does)
- [Problem Statement & Solution](#-problem-statement--solution)
- [Key Features](#-key-features)
- [System Architecture](#%EF%B8%8F-system-architecture)
- [Hardware Used](#-hardware-used)
- [How It Works](#-how-it-works)
- [Future Scope](#-future-scope)
- [Team](#-team)

---

## 🎯 What This Project Does

This contactless track monitoring robot:

1. **Travels autonomously** along railway tracks using 4 BO motors
2. **Detects track cracks** using dual IR sensors — contactlessly
3. **Detects obstacles** on the track in real-time
4. **Triggers instant alerts** — Buzzer (audio) + LED (visual) on any fault
5. **Requires zero train stoppage** — fully independent operation
6. **Runs on a portable Li-ion battery pack** — no external power needed

---

## 🚨 Problem Statement & Solution

### **Problem**

Railway track safety is a critical challenge across India:

- **Track Cracks** → Major cause of train derailments
- **Manual Inspection** → Slow, dangerous, and covers limited area
- **No Continuous Monitoring** → Faults go undetected between inspections
- **Obstacles on Track** → Detected too late for human inspectors

### **Our Solution**

A **compact autonomous robot** that:

✅ Travels along the track independently (no train needed)  
✅ Uses **2× IR Sensors** for crack detection + track alignment  
✅ Triggers **Buzzer + LED** instantly on fault detection  
✅ Motors stop automatically when a fault is found  
✅ Low-cost hardware — affordable to deploy at scale  

### **Impact**

- Reduces risk of derailments through early crack detection
- Eliminates danger of manual track inspection
- Can run continuously without disrupting train operations
- Scalable — multiple robots can cover large rail networks

---

## ✨ Key Features

### 🤖 **Autonomous Movement**
- 4× BO motors for smooth track traversal
- BTS7960 motor driver for precise control
- Auto-stop on fault detection

### 🔬 **Dual IR Sensing**
- IR Sensor 1 → Track alignment (keeps robot on track)
- IR Sensor 2 → Crack & obstacle detection
- Contactless detection — no physical contact with track surface

### ⚡ **Instant Fault Alerts**
- **Buzzer** → Audio alert triggered immediately on fault
- **LED** → Visual indicator for fault location
- **Motor stop** → Robot halts at fault point

### 🔋 **Portable Power**
- Li-ion Battery Pack — fully wireless operation
- No external wiring or power source required

---

## 🏗️ System Architecture

```
┌─────────────────────────────────────────────┐
│              ESP32 (Central Controller)     │
│  • Reads IR sensor data                     │
│  • Controls motor driver                    │
│  • Triggers buzzer & LED on fault           │
└───────┬──────────────┬──────────────────────┘
        │              │
┌───────▼──────┐  ┌────▼────────────────────┐
│  IR Sensor 1 │  │      IR Sensor 2        │
│  (Alignment) │  │  (Crack/Obstacle Det.)  │
└──────────────┘  └─────────────────────────┘
        │
┌───────▼─────────────────────────────────────┐
│           BTS7960 Motor Driver              │
│           Controls 4× BO Motors            │
└───────┬─────────────────────────────────────┘
        │
┌───────▼──────────────────────────────────┐
│         On Fault Detected:               │
│   Motors STOP + Buzzer ON + LED ON       │
└──────────────────────────────────────────┘
```

**Data Flow:**  
IR Sensors → ESP32 reads data → Motor driver controls movement → On fault: motors stop + buzzer + LED activate instantly

---

## 🛠️ Hardware Used

| Component | Quantity | Function |
|-----------|----------|----------|
| **ESP32** | 1 | Central controller — processes all sensor data |
| **IR Sensor** | 2 | Track alignment + crack/obstacle detection |
| **BO Motor** | 4 | Robot movement along the track |
| **BTS7960 Motor Driver** | 1 | Controls all 4 motors |
| **Li-ion Battery Pack** | 1 | Wireless portable power supply |
| **Buzzer** | 1 | Audio alert on fault detection |
| **LED** | 1 | Visual alert on fault detection |

---

## 📸 Screenshots

### Robot Hardware
![Robot Hardware](https://via.placeholder.com/800x400?text=Robot+Hardware+Photo)

### Circuit Diagram
![Circuit Diagram](https://via.placeholder.com/800x400?text=Circuit+Diagram)

### Fault Detection Demo
![Fault Detection](https://via.placeholder.com/800x400?text=Fault+Detection+Demo)



---

## ⚙️ How It Works

### **Normal Operation**
1. Robot powers on and begins moving along the track
2. IR Sensor 1 continuously checks track alignment — keeps robot centered
3. IR Sensor 2 scans for cracks and obstacles ahead
4. ESP32 processes both sensor inputs in real-time
5. Motors run continuously while no fault is detected

### **Fault Detection**
1. IR Sensor 2 detects a crack or obstacle
2. ESP32 immediately triggers fault response:
   - **All 4 motors STOP** — robot halts at fault location
   - **Buzzer activates** — audio alert
   - **LED turns ON** — visual indicator
3. Fault is flagged for human inspection at that exact location

---

## 🔮 Future Scope

| Add-on | Benefit |
|--------|---------|
| **GPS Module** | Pinpoint exact fault location on a map |
| **Camera Module + AI** | Crack severity classification using computer vision |
| **Ultrasonic Sensor** | Precise obstacle distance measurement |
| **GSM Module** | Remote SMS alerts to control center |

---

## 👥 Team

**Team sDx Legends** — Inverthon 2.0  
**Institute**: Invertis University  
**Category**: Hardware

| Name | Role |
|------|------|
| **Abhinav Srivastava** | R&D &Embedded Systems Lead |
| **Shekhar Singh** | R&D & Circuit Integration Lead |
| **Moh. Junaid** | Testing & Presentation Lead |
| **Tanishka Agarwal** | Documentation & Content Lead |


---

## 📄 License

This project is developed for Inverthon 2.0, Invertis University.

---

**Made with ❤️ by Team sDx Legends @ Inverthon 2.0 🔥**

⭐ Star this repo if you find it helpful!
