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

|               |STM8S003F3| ATTINY1616 | ATmega168P | CH32V003   |
|---------------|----------|------------|------------|------------|
| Max Frequency | 16 Mhz   | 20 Mhz     | 16Mhz      | 48Mhz      |
| Flash         | 8KB      | 16KB       | 16KB       | 16KB       |
| SRAM          | 1KB      | 2KB        | 1KB        | 2KB        |
| EEPROM        | 128B     | 128B       | 512B       |            |
| GPIO count    | 15       | 18         | 23         | 14         |
|               |          |            |            |            |
| UART          | Yes      | Yes        | Yes        | Yes        |
| I2C           | Yes      | Yes        | Yes        | Yes        |
| SPI           | Yes      | Yes        | Yes        | Yes        |
| Timers        | 3        | 4          | 3          | 2          |
| ADC pins      | 5        | 12         | 8          | 6          |

## Board Pinout

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/45ed0a8f-a25d-4bd4-a148-2691da45e4e8)

## MCU Pinout 

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/c9f1920d-3b20-4dc9-bd7b-12b9478671d3)

## How to programm

To program the STM8S microcontroller, you will need ST-LINK programmer or any compatible programmer supporting SWIM interface. Most common in the field is to use ST-Link USB dongle

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/8ad6dacd-b6f9-460d-8f93-675791bfa880)

You need to connect GND, SWIM and RESET. +5V is optional as long as you power board from the USB

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/3ae82208-da56-4e56-a6ae-d475589cb3b9)

### Arduino IDE

Add [https://github.com/tenbaht/sduino/raw/master/package_sduino_stm8_index.json](https://github.com/tenbaht/sduino/raw/master/package_sduino_stm8_index.json) to the board manager

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/848c1d02-bcef-44e4-8aa7-0268ce2bbb41)

After that you should install **sduino** from Board Manager

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/06826c66-ae04-4d27-8ccf-7e85def975dd)

Select **STM8S103F3** as target and other necessary settings in the board settings after

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/aba9733c-d2da-422f-8c37-b8b57fe73110)

Next press Build or Upload button, it should just work

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/1c6556ca-1988-452f-b325-d9659b8f1dc5)

### Platformio IDE
 
After installing [Plarformio IDE](https://platformio.org/platformio-ide), open sample [arduino project](/firmware/stm8-blink-arduino) or [native project](/firmware/stm8-blink-native). Run `Build` command to install necessary tools and libraries. 

Next run `Upload: stm8s003-dev-board` task if you're using stlinkv2 programmer. `Monitor` task should give you Serial monitor, as long as you have your board connected via USB as well.

## TODO (Work in Progress)

- Firmware samples
  - UART
  - RGB led (requires library)
  - Debugging (it should just work in Plarformio)  

## Hardware

Board schematic can be found in the [hardware](/hardware) section

![image](https://github.com/sonocotta/stm8s003-dev-board/assets/5459747/6fb33c9c-5b36-4d92-8bd5-f986b710f759)

- ![image](https://user-images.githubusercontent.com/5459747/206929567-5a68f822-1172-459c-bb34-64ab1ee2019c.png) STM8S003 MCU 
- ![image](https://user-images.githubusercontent.com/5459747/206929597-8f1b7a41-9ef4-4301-9d88-fdd6952fe900.png) CH340E USB-Serial Adapter connected to Hardware Serial
- ![image](https://user-images.githubusercontent.com/5459747/206929650-72bfa8ba-716a-4830-ae14-a2c6ddff8830.png) WS2812B RGB LED
- ![image](https://user-images.githubusercontent.com/5459747/206929704-bb9a66ee-7e48-4c81-87f7-1f0c60d1a02f.png) Programming and Debug header
- ![image](https://user-images.githubusercontent.com/5459747/206929744-5f7abffb-341e-49c9-8988-01835a2045a8.png) Hardware Reset button
- ![image](https://user-images.githubusercontent.com/5459747/206929801-e55e502e-bdce-4d85-a376-3268b96dc5e2.png) VIN disconnect - cut this line to disconnect LDO chip and power-on LED, recommended for low-power applications

## Where to buy

TBD

## Links

- [Product Page](https://www.st.com/en/microcontrollers-microprocessors/stm8s003f3.html)
