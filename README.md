# Car Door Safety System with Buzzer Alert

## Description
This project demonstrates communication between two microcontrollers using USART (Universal Synchronous Asynchronous Receiver Transmitter) and includes control of a buzzer based on the received data. One microcontroller is responsible for controlling a DC motor based on button input, while the other microcontroller receives the motor status and controls a buzzer accordingly.


# Project Overview

This project comprises two microcontroller programs designed to simulate a car's operation and door status, with the ability to trigger a buzzer alarm based on specific conditions. The primary objectives of each microcontroller are as follows:

### Microcontroller 1: Car Simulation Controller
- This microcontroller emulates the motion of a car.
- It is equipped with two buttons: Button 1 and Button 2.
- Button 1 simulates the car's movement and controls a DC motor.
- Button 2 simulates the door's open/close status.
- When the DC motor is active (car is moving) and the door is open, Microcontroller 1 will send a signal via USART.

### Microcontroller 2: Buzzer Controller
- This microcontroller receives signals from Microcontroller 1 via USART.
- It interfaces with a buzzer.
- When it receives a specific signal ('B') from Microcontroller 1, indicating that the car is moving with an open door, it triggers the buzzer as an alarm.

## Project Operation
The project's functionality can be summarized as follows:
1. Microcontroller 1 simulates the car's movement when Button 1 is pressed, activating a DC motor.
2. The status of the door is controlled using Button 2.
3. If the DC motor is running (indicating the car is in motion) and Button 2 is pressed (indicating the door is open), Microcontroller 1 sends a signal ('B') via USART to Microcontroller 2.
4. Microcontroller 2, upon receiving the 'B' signal, activates the buzzer to sound an alarm.

This project serves as a simple yet illustrative example of inter-microcontroller communication and conditional control of external hardware components, making it suitable for educational and demonstrative purposes.

## Hardware and Software Requirements
To replicate this project, you will need the following components:
- Two microcontrollers (STM32)
- A DC motor and associated circuitry (connected to Microcontroller 1)
- Buttons or switches for user input (connected to Microcontroller 1)
- A buzzer and associated circuitry (connected to Microcontroller 2)
- Appropriate power supply and connections
- Development environments for both microcontrollers (e.g., STM32CubeIDE)
- Microcontroller board support packages (BSP)
- Libraries for GPIO, USART, and Buzzer control

## Usage
1. Flash the firmware for Microcontroller 1 into one of the microcontrollers.
2. Flash the firmware for Microcontroller 2 into the other microcontroller.
3. Connect the two microcontrollers via USART (TX and RX pins).
4. Connect the DC motor to Microcontroller 1.
5. Connect the buzzer to Microcontroller 2.
6. Power up both microcontrollers.
7. Press Button 1 on Microcontroller 1 to activate the DC motor (simulate car movement).
8. Press Button 2 on Microcontroller 1 to simulate door open/close.
9. If the car is moving (DC motor is active) and the door is open, Microcontroller 1 will send a 'B' signal to Microcontroller 2, triggering the buzzer alarm.

---

*Author: Mohamad Ahmed Mohamad Abdelmoniem*

*Created on: August 15, 2023*


---
