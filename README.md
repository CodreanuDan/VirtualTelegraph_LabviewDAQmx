# 🛰️ Virtual Telegraph using NI DAQ and LabVIEW

A virtual telegraph system developed in LabVIEW, capable of transmitting and receiving Morse code signals through a National Instruments DAQ interface. The system simulates real-world telegraphy using analog signal generation, acquisition, and signal processing logic.

📄 [📘 Project Documentation (PDF)](https://github.com/CodreanuDan/VirtualTelegraph_LabviewDAQmx/blob/main/DOCS/Documents/CodreanuDan_TelegrafVirtual.pdf)
---

## 📡 System Overview

This project implements a LabVIEW-based virtual telegraph that:
- Encodes alphanumeric strings into Morse code.
- Converts Morse symbols into analog sinusoidal signals.
- Transmits signals through NI USB DAQ devices.
- Reconstructs and decodes the received signals into human-readable messages.

### 📷 Principle Diagram  
![Principle Diagram](https://github.com/user-attachments/assets/7ecbd836-00a5-4c16-8eed-97f4ad86423b)

### 📷 Hardware Architecture  
![Hardware Diagram](https://github.com/user-attachments/assets/0447d356-9bd4-4d4c-9eaf-1cc538a33178)


---

## 🧠 LabVIEW Components

The system consists of the following VIs and executables:

- `Analog Output.vi` – Generates the analog waveform based on a boolean signal pattern.
- `CW Transmit.vi` – Converts text to Morse code and prepares signal for output.
- `CW Transmitter.exe` – Standalone executable for Morse signal transmission.
- `Convert_Message_For_Signal_Processing.vi` – Converts decoded wave into Morse ASCII.
- `Morse_Decoder.vi` – Reconstructs message from analog waveform based on signal periods.
- `SigPeriod.vi` – Calculates signal period for each waveform cycle.

### 📷 Transmitter
- Block Diagram  
  ![Transmitter Block Diagram](https://github.com/user-attachments/assets/cb98ddb8-ead6-4906-b2a2-ca25a3d2595c)

- Front Panel  
  ![Transmitter Front Panel](https://github.com/user-attachments/assets/ed4133cb-5612-48f2-96a5-42e27b446261)


### 📷 Receiver
- Block Diagram  
  ![Receiver Block Diagram](https://github.com/user-attachments/assets/11f32a29-e686-4b47-9d4f-15e30ee38b3a)

- Front Panel  
  ![Receiver Front Panel](https://github.com/user-attachments/assets/a4c1aa7a-dfeb-4e56-b62d-1012b339f1ef)


---

## 🧩 How It Works

### ✉️ Data Transmission
- Input message is parsed and translated to Morse code.
- Morse characters are converted into a boolean sequence (e.g., `TFTTTF`).
- The boolean signal is used to generate a sinusoidal waveform with 5V amplitude.
- The waveform is transmitted via `ao0` output port using DAQmx.

#### 📷 Transmission Flow Diagram  
![Transmission Flow](https://github.com/user-attachments/assets/934b2c0c-9a00-464f-87c7-013eae8def91)

### 📥 Data Reception
- The signal is acquired using `ai0` input port with 5kHz sampling.
- Periods of the waveform are measured every 10ms.
- A FIFO buffer monitors the message window and triggers decoding.
- Period lengths are interpreted as dots, dashes, and pauses.
- The final output is decoded Morse, filtered and displayed as ASCII.

#### 📷 Reception Flow Diagram  
![Reception Flow](https://github.com/user-attachments/assets/298a1563-cb1d-482a-aaba-f05c23033010)

---

## 🧪 Tests and Results

### ✅ Test: Transmitting `Dan Dan`
- **Transmitter Panel**  
  ![TX Dan Dan](https://github.com/user-attachments/assets/5aef6541-cb89-4817-a8b2-7fa8d59ebc11)
- **Oscilloscope**  
  ![Oscilloscope Dan Dan](https://github.com/user-attachments/assets/090026bf-2991-4b6a-a982-bfe5759019f1)
- **Receiver Panel**  
  ![RX Dan Dan](https://github.com/user-attachments/assets/c976f374-4c32-42e0-8e4a-85ad5678cf0f)

---

## 🛠️ Hardware Configuration

| Parameter       | Value                             |
|----------------|-----------------------------------|
| DAQ Device      | NI USB-6008/6281                  |
| Analog Output   | ao0, RSE, 10kHz, ±5V amplitude     |
| Analog Input    | ai0, RSE, 5kHz sampling            |
| Signal          | Sine wave, 5V amplitude            |
| Timing          | 1 unit ≈ 100ms (dot)               |

---

