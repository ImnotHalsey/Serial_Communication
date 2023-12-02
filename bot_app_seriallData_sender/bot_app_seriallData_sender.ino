# Bot to APP

#include <SoftwareSerial.h>
#include <ArduinoJson.h>

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

void printSensorData(const SensorData& data) {
    printf("Timestamp: %ld\n", data.timestamp);
    printf("Bot battery: %d\n", data.botBattery);
    printf("T1 Motor temperature: %d\n", data.t1MotorTemperature);
    printf("Lights: %d\n", data.waterLevel);
    printf("Emergency: %d\n", data.EmergencyAlert);
}

SensorData generateRandomSensorData() {
    SensorData data;
    data.timestamp = 0;
    data.botBattery = random(45, 61);  
    data.t1MotorTemperature = random(15, 121);  
    data.waterLevel = random(0,101);  
    data.EmergencyAlert = random(0,4);  /
    return data;
}

void sendData(const SensorData& data) {
    String jsonMessage = "{\"timestamp\":" + String(data.timestamp) +
                         ",\"Bot_battery\":" + float(data.botBattery) +
                         ",\"T1_Motor_temperature\":" + String(data.t1MotorTemperature) +
                         ",\"T2_Motor_temperature\":" + String(data.t1MotorTemperature) + 
                         ",\"T3_MotorDriver_temperature\":" + String(data.t1MotorTemperature) +  
                         ",\"WaterLevel\":" + float(data.waterLevel) +  
                         ",\"EmergencyAlert\":" + String(data.EmergencyAlert) + "}";  
    mySerial.write(jsonMessage.c_str());
    Serial.println("Sent: " + jsonMessage);
}

void loop() {
    sendData(generateRandomSensorData());

    delay(1000);
}
