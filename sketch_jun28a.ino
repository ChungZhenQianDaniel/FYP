//------style guard ----

#ifdef __cplusplus

extern "C" {

#endif

uint8_t temprature_sens_read();

#ifdef __cplusplus

}

#endif

uint8_t temprature_sens_read();

// libraries needed


#include "DHT.h"

#include "ThingSpeak.h"

#include <CO2Sensor.h>



//-----ThingSpeak channel details

unsigned long myChannelNumber = 3;

const char * myWriteAPIKey = "QWYVT8CC71ELDUNG";

//----- Timer variables

unsigned long lastTime = 0;

unsigned long timerDelay = 1000;

//----DHT declarations

#define DHTPIN 4 // Digital pin connected to the DHT sensor

#define DHTTYPE DHT22 // DHT 22

// Initializing the DHT22 sensor.

DHT dht(DHTPIN, DHTTYPE);

// Initializing Co2 Sensor
CO2Sensor co2Sensor(A0, 0.99, 100);

 
void setup()
{

Serial.begin(115200); //Initialize serial



}

// Print local IP address and start web server


//----initialize dht22

dht.begin();

// calibrate Co2Sensor
co2Sensor.calibrate();

ThingSpeak.begin(client); // Initialize ThingSpeak

}

void loop()
{

if ((millis() - lastTime) > timerDelay)

{

delay(15000);

// 1500 delay for thinkspeak free account limit

float c = co2Sensor.read();

float h = dht.readHumidity();

// Read temperature as Celsius (the default)

float t = dht.readTemperature();

float f = dht.readTemperature(true);

if (isnan(h)  isnan(t)  isnan(f)) {

Serial.println(F("Failed to read from DHT sensor!"));

return;

}



Serial.print("Temperature (ºC): ");

Serial.print(t);

Serial.println("ºC");

Serial.print("Humidity: ");

Serial.println(h);

Serial.print("CO2 Level (ppm): ");

Serial.print(c);

ThingSpeak.setField(1, h);

ThingSpeak.setField(2, t);

ThingSpeak.setField(3, c);

// Write to ThingSpeak. 

int x = ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);

// ThingSpeak error code 200 stands for succesful
if(x == 200){

Serial.println("Channel update successful.");

}

else{


Serial.println("Problem updating channel. HTTP error code " + String(x));

}

lastTime = millis();

}

}