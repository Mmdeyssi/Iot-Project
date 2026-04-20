# IoT Temperature & Humidity Monitor

> Real-time environmental monitoring system using ESP8266 and cloud dashboard

![Platform](https://img.shields.io/badge/Platform-ESP8266%20NodeMCU-blue?style=flat-square)
![Protocol](https://img.shields.io/badge/Protocol-MQTT-purple?style=flat-square)
![Cloud](https://img.shields.io/badge/Cloud-ThingSpeak%20%7C%20Azure%20IoT-0078D4?style=flat-square)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=flat-square)

---

## 📡 What is this project?

A fully functional **IoT monitoring system** that reads temperature and humidity data from a DHT11 sensor connected to an **ESP8266 NodeMCU**, transmits it to the cloud via **MQTT**, and displays live readings on a **ThingSpeak dashboard** with **WebSocket** for real-time browser updates.

---

## ✨ Features

- 🌡️ Real-time temperature and humidity sensing via DHT11
- 📡 Data transmission over **MQTT protocol** to cloud backend
- ☁️ Live dashboard on **ThingSpeak** with automatic chart updates
- 🔄 **WebSocket** integration for instant browser-side updates
- 🔌 Low-power embedded design on ESP8266 NodeMCU

---

## 🏗️ System Architecture

```
┌─────────────────────┐
│   DHT11 Sensor      │
│  Temp + Humidity    │
└────────┬────────────┘
         │ GPIO Data Pin
┌────────▼────────────┐
│  ESP8266 NodeMCU    │
│  WiFi + MQTT Client │
└────────┬────────────┘
         │ MQTT over WiFi
┌────────▼────────────┐
│   MQTT Broker       │
│ (Cloud / Beebotte)  │
└────────┬────────────┘
         │
┌────────▼────────────┐      ┌─────────────────────┐
│  ThingSpeak Cloud   │      │   Web Browser        │
│  Live Charts        │      │   WebSocket Updates  │
└─────────────────────┘      └─────────────────────┘
```

---

## 🛠️ Tech Stack

| Component | Technology |
|---|---|
| Microcontroller | ESP8266 NodeMCU |
| Sensor | DHT11 (Temperature & Humidity) |
| Communication | MQTT protocol |
| Cloud Platform | ThingSpeak / Azure IoT Hub |
| Real-time Updates | WebSocket |
| Data Format | JSON |
| IDE | Arduino IDE |
| Language | C++ (Arduino) |

---

## 🔌 Hardware Requirements

- ESP8266 NodeMCU board
- DHT11 temperature & humidity sensor
- Jumper wires
- USB cable for programming
- WiFi connection

## Wiring

| DHT11 Pin | ESP8266 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DATA | D4 (GPIO2) |

---

## 🚀 Getting Started

### Prerequisites
- Arduino IDE with ESP8266 board support
- Libraries: `DHT sensor library`, `PubSubClient` (MQTT), `ESP8266WiFi`

### Installation

```bash
# Clone the repository
git clone https://github.com/Mmdeyssi/Iot-Project.git
cd Iot-Project
```

1. Open `project.ino` in Arduino IDE
2. Install required libraries via **Tools → Manage Libraries**
3. Update WiFi credentials and MQTT broker details in the config section:

```cpp
const char* ssid     = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqttServer = "YOUR_MQTT_BROKER";
```

4. Select **NodeMCU 1.0 (ESP-12E Module)** as board
5. Upload to your ESP8266

---

## 📊 Dashboard

Data is visualized in real time on ThingSpeak with:
- Temperature over time chart
- Humidity over time chart
- Live numeric readings

---

## 👤 Author

**Mouhib Mdaissi**
- 📍 Heidelberg, Germany
- 💼 [linkedin.com/in/mouhib-mdaissi-2262b21ab](https://www.linkedin.com/in/mouhib-mdaissi-2262b21ab)
- 🐙 [github.com/mmdeyssi](https://github.com/mmdeyssi)
