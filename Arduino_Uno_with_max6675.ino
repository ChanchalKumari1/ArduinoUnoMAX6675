#include <max6675.h>
//
// MAX6675 pins
#define SCK_PIN  9
#define CS_PIN   6
#define SO_PIN   7

// Relay pin
#define RELAY_PIN 8

// Temperature threshold (°C) - CHANGE THIS to your desired trigger temp
#define TEMP_THRESHOLD 30.0

MAX6675 thermocouple(SCK_PIN, CS_PIN, SO_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Relay OFF at start
  
  Serial.println("MAX6675 + Relay Ready");
  Serial.print("Threshold set to: ");
  Serial.print(TEMP_THRESHOLD);
  Serial.println(" °C");
  delay(500);
}

void loop() {
  float tempC = thermocouple.readCelsius();
  float tempF = thermocouple.readFahrenheit();

  // Check for sensor error
  if (isnan(tempC)) {
    Serial.println("Thermocouple ERROR! Check wiring.");
    digitalWrite(RELAY_PIN, LOW); // Safety: turn OFF relay
    delay(1000);
    return;
  }

  // Print temperature
  Serial.print(millis() / 1000.0, 3);
  Serial.print(" --> Temp: ");
  Serial.print(tempC);
  Serial.print(" °C  |  ");
  Serial.print(tempF);
  Serial.println(" °F");

  // Relay control
  if (tempC >= TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Relay ON
    Serial.print(millis() / 1000.0, 3);
    Serial.println(" --> Relay: ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Relay OFF
    Serial.print(millis() / 1000.0, 3);
    Serial.println(" --> Relay: OFF");
  }

  delay(1000);
}