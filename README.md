# Forest Safety and Conservation System

This forest monitoring system prototype is designed in an effort to preserve forest areas and to improve the security level for valuable trees which have high demand in market. Since it’s based on Wireless communication, alerts are quick.
PIR Motion Sensor, Sound Sensor, Flame Sensor, Temperature Sensor and GPS Module are used in the development of this project. These sensing devices are connected to a Micro controller which has an NRF Wireless Transceiver attached to it for sending alerts with accurate GPS coordinates data.
For theft detection we use PIR Motion Sensor & Sound Sensor, when a person walks by the field of range of PIR Motion sensor, it detects the motion and sends signals to the microcontroller, when a loud noise (i.e chain-saw noise) is detected by the sound sensor it sends signal to the microcontroller, the microcontroller utilizes the NRF Transceiver connected to it to send alert message wirelessly to the operator.
If forest fire occurs, temperature sensor checks for the rising temperature and flame sensor detects fire by measuring levels of radiation in the atmosphere and sends a signal to the microcontroller and fire alerts are sent to operator.
These alerts are sent with accurate GPS location coordinates for the department or community forest management office to track the exact location where theft is being committed or where forest fire is spreading.
![transmitter names](https://github.com/niroopcn/forest_arduino/assets/70747194/015c83b7-c14f-4be7-9ad3-d1503f6c3c8a)
![receiver names](https://github.com/niroopcn/forest_arduino/assets/70747194/d0b6fd85-22d3-482d-8988-e4bd03c21d19)
