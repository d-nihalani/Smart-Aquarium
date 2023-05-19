#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>


#define LM35_PIN GPIO_NUM_32 
#define button1_vpin V3 
#define button2_vpin V4
#define BLYNK_TEMPLATE_ID "TMPL3AEcug53d"
#define BLYNK_TEMPLATE_NAME "Aquarium Template"
#define BLYNK_AUTH_TOKEN "4lxOqqHLnVcCAuc_FABxYR5ak22_l_J3"
#define BLYNK_PRINT Serial
Servo servo;

char ssid[] = "moto g72_6167";
char pass[] = "trek5050";


BlynkTimer timer;


BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V1, s0);
}

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
  // Check these values and turn the relay2 ON and OFF
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
  float temperature = ((sensorValue) * 100.0)+10; 
  // Send temperature value to Blynk app
  Blynk.virtualWrite(V5, temperature);
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  servo.attach(13);
  servo.write(0);
  pinMode(12, OUTPUT); // set relay channel 1 to output
  pinMode(14, OUTPUT); // set relay channel 2 to output
  digitalWrite(14,HIGH);
  digitalWrite(12,HIGH);
  
  timer.setInterval(1000L, sendTemperature); 
}

void loop() 
{
  Blynk.run();
  timer.run();
}
