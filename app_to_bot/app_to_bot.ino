// Bot To APP --> Mode 50-100ms communication
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

// Class for all communication processing ...
class SensorDataProcessor {
public:
    long get_timestamp() { return 0; }
    int get_Message_ID() { return random(1001, 1099); }
    int get_Control_mode() { return random(0, 3); }
    int get_path_mode() { return random(0, 2); }
    int get_lights() { return random(0, 2); }
    int get_Emergency() { return random(0, 2); }
    int get_tool_type() { return random(0, 7); }

    void ArrayMaker(int* results) {
        // Store results in the array
        results[0] = get_timestamp();
        results[1] = get_Message_ID();
        results[2] = get_Control_mode();
        results[3] = get_path_mode();
        results[4] = get_lights();
        results[5] = get_Emergency();
        results[6] = get_tool_type();
    }
};

void HomeDataProcessor(int* results) {
    for (int i = 0; i < 7; ++i) {
        Serial.print(results[i]);
        Serial.print(" ");
    }
    Serial.println();  
}

void loop() {
    SensorDataProcessor dataProcessor;
    int results[7];
    dataProcessor.ArrayMaker(results);
    HomeDataProcessor(results);
    delay(1000);
}
