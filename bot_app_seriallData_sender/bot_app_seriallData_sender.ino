//  Bot To APP 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

struct SensorData {
    long timestamp;
    int botBattery;
    int t1MotorTemperature;
    int waterLevel;
    int EmergencyAlert;
};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

SensorData generateRandomSensorData() {
    SensorData data;
    data.timestamp = 0;
    data.botBattery = random(45, 61);
    data.t1MotorTemperature = random(15, 121);
    data.waterLevel = random(0, 101);
    data.EmergencyAlert = random(0, 4);
    return data;
}

void sendData(const SensorData& data) {
    mySerial.write((uint8_t*)&data, sizeof(SensorData));
    Serial.println("Sent data as an array");
}

void loop() {
    SensorData randomData = generateRandomSensorData();
    sendData(randomData);
    delay(1000);
}
