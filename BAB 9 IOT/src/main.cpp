#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 27      // Pin data sensor DHT
#define DHTTYPE DHT22  // Tipe sensor DHT

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx Test!"));
  dht.begin();
}

void loop() {
  delay(500);  // Delay untuk pembacaan data

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();       // Suhu dalam Celsius
  float tempF = dht.readTemperature(true);   // Suhu dalam Fahrenheit

  // Cek jika pembacaan gagal
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float heatIndexF = dht.computeHeatIndex(tempF, humidity);     // Indeks panas dalam Fahrenheit
  float heatIndexC = dht.computeHeatIndex(tempC, humidity, false); // Indeks panas dalam Celsius

  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(tempC);
  Serial.print(F("°C "));
  Serial.print(tempF);
  Serial.print(F("°F  Heat index: "));
  Serial.print(heatIndexC);
  Serial.print(F("°C "));
  Serial.print(heatIndexF);
  Serial.println(F("°F"));
}
