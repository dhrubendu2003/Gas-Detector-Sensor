#include "thingProperties.h"

#define GAS_SENSOR_PIN 34
#define LED_PIN        25
#define GAS_THRESHOLD  600  // Adjust based on environment

void setup() {
    Serial.begin(115200);
    delay(1500);

    pinMode(GAS_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    initProperties();
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);
    setDebugMessageLevel(2);
    ArduinoCloud.printDebugInfo();
}

void loop() {
    ArduinoCloud.update();

    int gasValue = analogRead(GAS_SENSOR_PIN);
    gasLevel = (float)gasValue; // Send to IoT Cloud

    Serial.print("Gas Level: ");
    Serial.println(gasValue);

    if (gasValue > GAS_THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);  // Turn on LED
    } else {
        digitalWrite(LED_PIN, LOW);   // Turn off LED
    }

    delay(2000);
}
