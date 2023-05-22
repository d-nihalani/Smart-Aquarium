//Libraries
#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

//initializing pins
#define LM35_PIN GPIO_NUM_32 
#define button1_vpin V3 
#define button2_vpin V4
//blynk connection parameters 
#define BLYNK_TEMPLATE_ID "Your-Template-ID-Here"
#define BLYNK_TEMPLATE_NAME "Your-Blynk-Template-Name"
#define BLYNK_AUTH_TOKEN "Your-Blynk-Token-Name"
#define BLYNK_PRINT Serial
Servo servo;

char ssid[] = "wifi_name";
char pass[] = "wifi_pwd";

int ledPin = 27;  // Pin connected to the LED
bool ledState = false;  // Variable that stores state of LED

BlynkTimer timer;

// v0 swtich for controlling servo manually
BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V1, s0); //v1 switch to display pos of servo
}

//v2 automatic feed with servo
BLYNK_WRITE(V2) 
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    servo.write(180); 
    Blynk.virtualWrite(V1, 180);  
    timer.setTimeout(2000, []() {
      servo.write(0);
      Blynk.virtualWrite(V1, 0);
    });
  }
}

BLYNK_WRITE(V3) // virtual pin V3 control pump 1
{
  bool value1 = param.asInt();
  // Check these values and turn the relay1 ON and OFF
  if (value1 == 1) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
}

BLYNK_WRITE(V4) // virtual pin V4 control pump 2
{
   bool value2 = param.asInt();
  // Check these values and turn the relay2 ON and OFF
  if (value2 == 1) {
    digitalWrite(14, HIGH);
  } else {
    digitalWrite(14, LOW);
  }
}

void sendTemperature() {
  // Read the analog voltage from LM35 sensor
  float sensorValue = analogRead(LM35_PIN) * (3.3 / 4095);
  // Convert the sensor value to temperature in degrees Celsius
  float temperature = ((sensorValue) * 100.0); 
  // Send temperature value to Blynk app
  Blynk.virtualWrite(V5, temperature);
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  servo.attach(13); //initialize servo input
  servo.write(0);   //initialize servo pos to 0
  pinMode(12, OUTPUT); // set relay channel 1 to output
  pinMode(14, OUTPUT); // set relay channel 2 to output
  digitalWrite(14,HIGH);
  digitalWrite(12,HIGH);  // set both relay state
  pinMode(ledPin, OUTPUT);
  
  timer.setInterval(10000, sendTemperature); 
  //send temp reading after every 10 seconds
}

void loop() 
{
  Blynk.run();
  timer.run();
  bool currentLedState = digitalRead(ledPin);

  // Update virtual button if LED state has changed
  if (currentLedState != ledState) {
    ledState = currentLedState;
    Blynk.virtualWrite(V6, ledState);
  }
}
