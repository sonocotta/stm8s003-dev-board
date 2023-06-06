# STM8S003 Development Board (Work in progress)

![Open Source Hardware](/doc/images/open-source-hardware-logo.png)
![Open Source Software](/doc/images/open-source-software-logo.png)

The STM8S003 development board is a low-cost and easy-to-use board that provides a drop-in replacement for the popular Arduino Nano. The board is based on the STM8S003F3 microcontroller, which offers high performance and low power consumption.

The development board features a compact design with a small form factor, making it easy to integrate into projects of all sizes. It includes all the necessary components for the microcontroller, including a USB port for easy programming and communication with a computer.

The STM8S003 development board is ideal for both hobbyists and professionals who want a simple, yet powerful development platform. It offers a wide range of features, including 16 MHz clock speed, 8 KB of flash memory, 1 KB of RAM, and 128 bytes of EEPROM. It also supports a variety of communication protocols, including SPI, I2C, and UART.

Additionally, the STM8S003 development board is compatible with the Arduino IDE, allowing users to take advantage of a large community of developers and a wide range of libraries and tools. This makes it easy to get started with programming, even for those who are new to the field.

Overall, the STM8S003 development board is an excellent choice for anyone who needs a low-cost and easy-to-use development platform that offers high performance and flexibility. Whether you are working on a hobby project or a professional application, this board has everything you need to get started quickly and easily.

![image](https://user-images.githubusercontent.com/5459747/231289408-4b4df2d3-ba5c-4a9d-8f13-00d72a6a58a7.png)

## Features

- [STM8S003F3](https://www.st.com/en/microcontrollers-microprocessors/stm8s003f3.html) 8-bit MCU in a 20-pin package
- Up to 16 MHz CPU clock
- 8 KB Flash
- 1 KB SRAM
- 128B of EEPROM 
- SWIM interface for flashing and debugging
- Onboard 5V LDO (disconnected for low power applications)
- Flash using Arduino IDE, Platformio, or the IDE of your choice
- Onboard USB-Serial bridge (CH340E) connected to hardware Serial port
- One RGB LED (WS2812B)
- One Push button

## STM8S003F3

STM8S003F3 is an entry-level 8-bit MCU in the STM8 line. Generally they offer what modern 8-bit MCU should deliver, including popular communication interfaces, low power consumption in sleep mode (down to few micro-amps) and ease of use.

## Board Pinout

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/45ed0a8f-a25d-4bd4-a148-2691da45e4e8)

## MCU Pinout 

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/c9f1920d-3b20-4dc9-bd7b-12b9478671d3)

## How to programm

To program the STM8S microcontroller, you will need ST-LINK programmer or any compatible programmer supporting SWIM interface. Most common in the field is to use ST-Link USB dongle

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/8ad6dacd-b6f9-460d-8f93-675791bfa880)

You need to connect GND, SWIM and RESET. +5V is optional as long as you power board from the USB

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/3ae82208-da56-4e56-a6ae-d475589cb3b9)


## TODO

- Arduino Core
- How to flash
- Using with Arduino IDE
- Using with Platformio IDE
- Firmware samples
  - UART
  - RGB led
  - Debugging
  

## Hardware

Board schematic can be found in the [hardware](/hardware) section

## Where to buy
