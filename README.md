# Smart Aquarium

## Description
Smart Aquarium is an IoT-based project that automates the monitoring and maintenance of an aquarium. The system includes a microcontroller unit that collects data from sensors and controls various components of the aquarium, such as a water pump, level-indicator, and a feeder. The system can also be controlled and monitored remotely through a mobile app.

## Components
- ESP32 MicroController
- LM35 temperature sensor
- SG90 Servo Motor
- 4 Channel Relay module
- 3-6V Water pump
- 5V power adapter
- Custom Water Level Indicator

- Arduino Libraries - Blynk by Volodymyr Shymanskyy, ServoESP32 by Jaroslav Paral
- Board Used ESP32 Dev Module

<div align="center">
  <img src="https://github.com/d-nihalani/Smart-Aquarium/blob/main/Circuit-Diagram.png" alt="Circuit Diagram">
</div>


## Features
- Real-time monitoring of temperature and water level inside the aquarium
- Automatic control of water pump and bubbler to maintain optimum water conditions
- Programmable feeding for customizing the aquatic's food
- BLynk Mobile/Web app for remote monitoring and control

## Getting Started
To build and deploy the project, follow these steps:
1. Connect the components as shown in the circuit diagram
2. Add requried libraries and boards mentioned.
3. Upload the sketch to the Arduino IDE
4. Rename your wifi credentials.
5. Install the Blynk mobile app on your smartphone and connect to a WiFi network.
6. Integrate Blynk Firmware configuration to your code. 
   (Blynk -> Devices-> YourDevice -> Device Info -> Firmware Configuration Code.)
7. Monitor and control your aquarium from anywhere with wifi

## Blynk Cloud
1. Download and install the Blynk app from your device's app store.
2. Create a new Blynk account and log in.
3. Create a new Blynk project and obtain the authentication token.

### Blynk Configuration

1. Open the Blynk templare in the app and configure the desired widgets.
2. Add a 7 widgets and assign it to a virtual pins (e.g., V0, V1).
3. Customize the button settings, such as style, colors, and labels.
4. Enable the "Read" option to receive the button state from the ESP32.
You can do this for web and mobile dashboard both. Refer to these screenshots for an idea.

![Blynk-Web-Template](https://github.com/d-nihalani/Smart-Aquarium/blob/main/srcs/wt.png)
![Blynk-Web-Device](https://github.com/d-nihalani/Smart-Aquarium/blob/main/srcs/wd.png)

![Blynk-Mobile-Template](https://github.com/d-nihalani/Smart-Aquarium/blob/main/srcs/mt.png)
![Blynk-Mobile-Control](https://github.com/d-nihalani/Smart-Aquarium/blob/main/srcs/mc.png)
 
## Future Scope
- Adding a pH sensor, Dissolved Oxygen Sensor, TDS sensor for monitoring water quality.
- Integration with voice assistants such as Amazon Alexa and Google Home
- Adding a camera for real-time streaming of the aquarium

## Credits
- [Blynk IoT Platform](https://blynk.io/) for the mobile app interface
- [Adafruit Industries](https://www.adafruit.com/) for providing useful libraries and tutorials

## License
This project is licensed under the GNU License - see the [LICENSE.md](LICENSE.md) file for details.
