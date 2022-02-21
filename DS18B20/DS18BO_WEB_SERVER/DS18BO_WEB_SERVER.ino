#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#include <OneWire.h>
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 4         // Your ESP8266 pin (ESP8266 GPIO 2 = WeMos D1 Mini pin D4)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "0_c6XxschV0ZfoF46U7HOSKK8xkzQK3t";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Malware repository";
char pass[] = "Yogesh@2002";

BlynkTimer timer;

float roomTemperature;            // Room temperature in F

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  sensors.begin();                        // Starts the DS18B20 sensor(s) 
}

void loop()
{
  Blynk.run();
  timer.run();
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(100);
  Blynk.virtualWrite(1, temperatureC);
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
