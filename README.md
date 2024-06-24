# Vending Machine with Reward-Based System

## Project Overview

This project is a prototype for a vending machine with a reward-based system. The primary functionality includes accepting coins to dispense a product, allowing users to dispose of waste, and dispensing a reward product if waste is disposed of correctly.

## Features

1. **Product Dispensing**: Accepts coins for product dispensing (one product used for this prototype).
2. **Waste Disposal Prompt**: Prompts the user to dispose of waste after dispensing a product.
3. **OTP Generation**: Generates and displays a one-time password (OTP) on the LCD for waste disposal.
4. **Bin Access Control**: Requires the user to enter the OTP to open the waste disposal bin.
5. **Automatic Bin Monitoring**: Uses an IR sensor to detect waste disposal and monitors for 10 seconds before closing the bin.
6. **Reward Dispensing**: Dispenses a reward product if waste is disposed of correctly.
7. **Reset Functionality**: Resets the machine to accept another order if the user does not wish to dispose of waste.

## Components

- **Arduino MEGA**: The main microcontroller.
- **Servo Motors (3)**: Used for various mechanical movements.
- **LCD (16x9)**: Displays information and OTP.
- **Keypad (4x4)**: Used for user input.
- **IR Sensor**: Detects the presence of waste in the disposal bin.
- **Coin Detector**: Detects coins for product dispensing.

## How It Works

1. **Coin Acceptance**: The machine accepts a coin for the product you need to dispense.
2. **Product Dispensation**: After the coin is accepted, the product is dispensed.
3. **Waste Disposal Prompt**: The machine prompts the user to dispose of waste.
4. **OTP Generation**: An OTP is generated and displayed on the LCD.
5. **User Decision**: The user can either dispose of waste or reset the machine:
    - **Dispose Waste**: The user enters the OTP on the keypad to open the disposal bin.
    - **Reset Machine**: If the user does not wish to dispose of waste, pressing a relevant key on the keypad resets the machine.
6. **Waste Detection**: If the user enters the OTP, the bin opens, and the IR sensor detects the waste disposal, monitoring for 10 seconds before closing the bin.
7. **Reward Dispensation**: If waste is detected, the machine dispenses a reward product.
8. **Machine Reset**: The machine resets and is ready to accept another order.

## Setup and Installation

### Hardware Setup

1. **Arduino MEGA**: Connect the Arduino MEGA to the other components as per the circuit diagram.
2. **Servo Motors**: Connect the three servo motors to the appropriate pins on the Arduino.
3. **LCD**: Connect the LCD to the Arduino and configure it for a 16x9 display.
4. **Keypad**: Connect the 4x4 keypad to the Arduino.
5. **IR Sensor**: Connect the IR sensor to detect waste in the disposal bin.
6. **Coin Detector**: Set up the coin detector to accept coins for product dispensing.

### Software Setup

1. **Arduino IDE**: Download and install the Arduino IDE.
2. **Libraries**: Ensure you have the necessary libraries installed for the LCD, keypad, and servo motors.


## Usage

1. **Start the Machine**: Power on the vending machine.
2. **Insert Coin**: Insert a coin to dispense the product.
3. **Dispose Waste**: Follow the prompts to dispose of waste and earn a reward.
4. **Enter OTP**: If disposing waste, enter the OTP displayed on the LCD.
5. **Receive Reward**: If waste is detected, collect your reward product.
6. **Reset Machine**: The machine resets and is ready for the next user.

## Contributing

Feel free to contribute to this project by submitting issues or pull requests.


Feel free to adjust this template to better suit the specifics of your project, including the actual file names, hardware connections, and any additional setup instructions or features.
