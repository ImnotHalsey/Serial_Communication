//  Bot To APP 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

struct SensorData {
    long timestamp;
    float botBattery;
    int t1MotorTemperature;
    int t2MotorTemperature;
    int t3MotorDriverTemperature;
    float waterLevel;
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
    data.t2MotorTemperature = random(15, 121);
    data.t3MotorDriverTemperature = random(15, 121);
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

//APP as a receiver , Just codes will be printed!

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

struct SensorData {
    long timestamp;
    float botBattery;
    int t1MotorTemperature;
    int t2MotorTemperature;
    int t3MotorDriverTemperature;
    float waterLevel;
    int EmergencyAlert;
};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

void receiveData(SensorData& data) {
    // Read data as an array of individual values
    if (mySerial.available() >= sizeof(SensorData)) {
        mySerial.readBytes((char*)&data, sizeof(SensorData));
    }
}

void printReceivedData(const SensorData& data) {
    Serial.print("[");
    Serial.print(data.timestamp);
    Serial.print(",");
    Serial.print(data.botBattery);
    Serial.print(",");
    Serial.print(data.t1MotorTemperature);
    Serial.print(",");
    Serial.print(data.t2MotorTemperature);
    Serial.print(",");
    Serial.print(data.t3MotorDriverTemperature);
    Serial.print(",");
    Serial.print(data.waterLevel);
    Serial.print(",");
    Serial.print(data.EmergencyAlert);
    Serial.println("]");
}

void loop() {
    SensorData receivedData;
    receiveData(receivedData);
    printReceivedData(receivedData);
    delay(1000);
}

