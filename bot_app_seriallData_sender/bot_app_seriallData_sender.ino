// Bot To APP 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

class SensorDataProcessor {
public:
  long get_timestamp() {return 0;} 

  int get_botBattery_voltage() {return random(45, 61);}

  int get_T1MortorTemp() {
    return random(15, 120);}

  int get_T2MortorTemp() {
    return random(15, 120);}

  int get_T3MortorDriverTemp() {
    return random(15, 120);}

  int get_WaterLevelValue() {
    return random(0, 101);}

  int get_Steering_angle() {
    return random(-60, 60);}

  int*  EmergencyAlert() {
    int results[] = {0, 0, 0,0, 0, 0,0, 0, 0, 0, 0,0};
    results[0] = get_timestamp();
    results[1] = get_botBattery_voltage();
    results[2] = get_T1MortorTemp();
    results[3] = get_T2MortorTemp();
    results[4] = get_T3MortorDriverTemp();
    results[5] = get_WaterLevelValue();
    results[6] = get_Steering_angle();

    if (results[1] <= 45 || results[1] >= 61) {
      Serial.println("Battery is going to Sambhavam!");
      results[7] = 1;
    }

    if (results[2] <= 15 || results[2] >= 120) {
      Serial.println("T1 Mortor is going to Sambhavam!");
      results[8] = 1;
    }

    if (results[3] <= 15 || results[3] >= 120) {
      Serial.println("T2 Mortor is going to Sambhavam!");
      results[9] = 1;
    }

    if (results[4] <= 15 || results[4] >= 120) {
      Serial.println("T3 Mortor Driver is going to Sambhavam!");
      results[10] = 1;
    }

    if (results[5] <= 15 || results[5] >= 100) {
      Serial.println("Low Water Level");
      results[11] = 1;
    }

    // Print the results array  // ----------> Write code to return the result list in the production 
    Serial.print("Results Array: ");
    for (size_t i = 0; i < sizeof(results) / sizeof(results[0]); ++i) {
      Serial.print(results[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
};

SensorDataProcessor sensor;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  sensor.EmergencyAlert();
  delay(1000);
}


//  Expected output
// 10:52:19.030 -> T3 Mortor Driver is going to Sambhavam!
// 10:52:19.063 -> Results Array: 0 47 46 98 15 41 0 0 0 1 0 