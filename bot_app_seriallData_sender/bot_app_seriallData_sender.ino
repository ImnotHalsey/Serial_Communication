//  Bot To APP 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

struct SensorData {
    long timestamp;
    float botBatteryVoltage;
    int t1MotorTemperature;
    int t2MotorTemperature;
    int t3MotorDriverTemperature;
    float waterLevel;
    int EmergencyAlert;};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

// Class for all sensory communication processing ...
class SensorDataProcessor {
public:
  //  get time stamp code.
  long get_timestamp() { return 0; }

  // get battery voltage
  float get_botBattery_voltage() { return random(45, 61); }

  // get T1 Mortor Temperature 
  int get_T1MortorTemp() { return random(15, 120); }

  // get T2 Mortor Temperature 
  int get_T2MortorTemp() { return random(15, 120); }

  // get T3 Mortor Driver Temperature 
  int get_T3MortorDriverTemp() { return random(15, 120); }

  // get waterLevel value 
  float get_WaterLevelValue() { return random(0, 101); }

  // get Emergency Alert
  int EmergencyAlert() {
    // Check the following parameters {WHAT IF MORE THAN ONE ERROR OCCURS! --> Need Confirmation}
      // --> Parameters will be checked from the above functions only 
        //  --> 1. checks water level 
        //  --> 2. checks current draw [low and high ] -- (of what need to be declared yet)
        //  --> 3. checks for Temperatures [low and High] -- (of motors[T1, T2] and drivers[T3])
        //  --> 4. checks for battery voltage level [Low and High]
        //  --> 5. Finally Gives the Error code according to the conditions above and Documentations 

    return random(0, 4);
  }
};


SensorData ArrayMaker() {
    SensorDataProcessor dataProcessor;
    SensorData data;

    data.timestamp = dataProcessor.get_timestamp();
    data.botBatteryVoltage = dataProcessor.get_botBattery_voltage();
    data.t1MotorTemperature = dataProcessor.get_T1MortorTemp();
    data.t2MotorTemperature = dataProcessor.get_T2MortorTemp();
    data.t3MotorDriverTemperature = dataProcessor.get_T3MortorDriverTemp();
    data.waterLevel = dataProcessor.get_WaterLevelValue();
    data.EmergencyAlert = dataProcessor.EmergencyAlert();

    return data;
}


void sendData(const SensorData & data) {
    mySerial.write((uint8_t*)&data, sizeof(SensorData));
    Serial.println("Sent data as an array");

    // Print individual values without a custom print function
    Serial.print("Timestamp: "); Serial.println(data.timestamp);
    Serial.print("Bot battery: "); Serial.println(data.botBatteryVoltage);
    Serial.print("T1 Motor temperature: "); Serial.println(data.t1MotorTemperature);
    Serial.print("T2 Motor temperature: "); Serial.println(data.t2MotorTemperature);
    Serial.print("T3 Motor Driver temperature: "); Serial.println(data.t3MotorDriverTemperature);
    Serial.print("Water Level: "); Serial.println(data.waterLevel);
    Serial.print("Emergency Alert: "); Serial.println(data.EmergencyAlert);

}

void loop() {
    SensorData randomData = ArrayMaker();
    sendData(randomData);
    delay(1000);
}

