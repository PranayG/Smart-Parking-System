# Smart-Parking-System
The Smart Parking System is a combination of a  self-driving robot with a smart parking garage, aims to decrease parking space search time. The self-driving robot is powered by a Parallax Basic Stamp 2 microcontroller, while the smart parking garage utilizes an Arduino Uno microcontroller.

## Objective
To develop an scalable working model of a smart parking system, we multiple IR and Ultrasonic sensors for navigation and parking detection on the Arduino and Basic Stamp2.

## Requirements

| Parts                    | Quantity | Price Per Unit |
|--------------------------|----------|----------------|
| Parallax Basic Stamp 2  | 1        | $60            |
| Arduino Uno R3          | 2        | $15            |
| NRF24L01 Wi-Fi module   | 2        | $5             |
| IR sensors              | 2        | $2             |
| Ultrasonic Sensor       | 4        | $4             |
| Parallax servo motor    | 2        | $10            |
| I2C LCD display         | 1        | $10            |
| Potentiometer           | 1        | $3             |
| Buttons                 | 1        | $2             |
| Kill switch             | 1        | $2             |
| Total Price             |          | $155           |

## Smart Parking

Within the intelligent parking facility, the presence of Arduino Uno is notable. This microcontroller is responsible for calculating the availability of empty parking spaces by collecting information from ultrasonic sensors installed at each parking space. The objective is to identify the nearest vacant parking spot from the total number of unoccupied spaces within the facility. After determining this optimal parking spot in relation to the vehicle, the data is transmitted to the intelligent vehicle using the NRF module which uses a wireless mode of communication with the Smart car.

<img src ="https://user-images.githubusercontent.com/9202531/221016787-40c54824-b9d3-4806-8639-8e65d7df3b49.png" width = "600" height="400">


## Smart Car

The intelligent robot is developed using the Boe-Bot kit from PARALLAX. It's driven by the Basic Stamp 2 microcontroller which is programmed using BASIC , which interfaces with the Arduino Uno to obtain information regarding parking space availability within the arena. This information is gathered through four ultrasonic sensors, each positioned at a parking space, and is transmitted wirelessly to the car.

Upon receiving this data, the BS2 microcontroller then activates 360 degree continuous servo motors to guide the robot to an unoccupied parking space and follow two infrared sensors have been affixed to the front of the robot to assist in its navigation along the designated path.

For advance stages of the project, the smart-car could naivgate using Vision based sensors for a much realistic experience.

<img src = "https://github.com/PranayG/Smart-Parking-System/assets/9202531/06edba56-5adf-4e5d-906d-fd94d5a13c76" width = "600" height="400">

### Wireless communication

The exchange of information relies between the transmission of the two NRF24L01 Wi-Fi modules, one located in the parking arena and the other in the smart car. 

The parking arena, in particular, can transmit data at speeds of up to 2 megabytes, using a series of transmissions to relay data from the ultrasonic sensors to the receiver at an exceptionally rapid pace.
The NRF module  operates within a 2.4 GHz ISM frequency band. he receiver, in turn, processes this incoming data, enabling the car to adjust its path based on information received from the parking arena regarding available parking spaces. The receiver itself is also equipped with an NRF24L1 Wi-Fi module, ensuring high-speed data reception to promptly implement any necessary path adjustments.

## Conclusion 

This project sums up a simple solution for a complex problem in the modern day. The requirement for saving fuel and time is becoming more necessary day by day. So, there was a solution proposed for communication between two systems such as parking arena and a smart car which then eventually helps in saving time and fuel of the car to be parked on its own in a huge parking space. This project is very crucial considering there is an acute need of finding sustainable solutions for our day-to-day tasks such as the one proposed and presented in this project.
