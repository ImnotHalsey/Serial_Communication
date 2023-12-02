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

void communication_processor(const SensorData& data) {
  Serial.print(data.timestamp); // Print data and time
  if (data.botBattery < 45 || data.botBattery > 60) {
    Serial.println("Anomalous battery values detected.");
  } else {
    Serial.print("Battery Voltage: ");
    Serial.println(data.botBattery);
  }

  if (data.t1MotorTemperature < 15 || data.t1MotorTemperature > 121) {
    Serial.println("Anomalous T1 Motor values detected.");
  } else {
    Serial.print("T1 Motor values are normal: ");
    Serial.println(data.t1MotorTemperature);
  }

  if (data.t2MotorTemperature < 15 || data.t2MotorTemperature > 121) {
    Serial.println("Anomalous T2 Motor values detected.");
  } else {
    Serial.print("T2 Motor values are normal: ");
    Serial.println(data.t2MotorTemperature);
  }

  if (data.t3MotorDriverTemperature < 15 || data.t3MotorDriverTemperature > 121) {
    Serial.println("Anomalous T3 Motor Driver values detected.");
  } else {
    Serial.print("T3 Motor Driver values are normal: ");
    Serial.println(data.t3MotorDriverTemperature);
  }

  if (data.waterLevel < 0 || data.waterLevel > 101) {
    Serial.println("Anomalous water level detected.");
  } else {
    Serial.print("Water level is normal: ");
    Serial.println(data.waterLevel);
  }

  switch (data.EmergencyAlert) {
    case 0:
      Serial.println("No Errors: 0");
      break;
    case 1:
      Serial.println("Low Water Level detected. Received code: 1");
      break;
    case 2:
      Serial.println("High Current detected. Received code: 2");
      break;
    case 3:
      Serial.println("High Temperature detected. Received code: 3");
      break;
    case 4:
      Serial.println("Low Battery detected. Received code: 4");
      break;
    default:
      Serial.println("Unknown Emergency Alert. Received code: " + String(data.EmergencyAlert)); // Need to assign a number for declaring no errors reported 
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
    communication_processor(receivedData);
    // printReceivedData(receivedData);
    delay(1000);
}


//      --> Expected Result <--
//    Battery Voltage: 53.00
//    T1 Motor values are normal: 117
//    T2 Motor values are normal: 95
//    T3 Motor Driver values are normal: 30
//    Water level is normal: 5.00
//    Low Battery detected. Received code: 0
//    [0,53.00,117,95,30,5.00,0]