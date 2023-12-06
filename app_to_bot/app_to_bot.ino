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
};

int* ArrayMaker() {
    static int results[7] = {0, 0, 0, 0, 0, 0, 0};
    SensorDataProcessor dataProcessor;

    // Store results in the array
    results[0] = dataProcessor.get_timestamp();
    results[1] = dataProcessor.get_Message_ID();
    results[2] = dataProcessor.get_Control_mode();
    results[3] = dataProcessor.get_path_mode();
    results[4] = dataProcessor.get_lights();
    results[5] = dataProcessor.get_Emergency();
    results[6] = dataProcessor.get_tool_type();

    return results;
}

void printer() {
    int* results = ArrayMaker();

    // Print results from the array
    Serial.print("Timestamp: ");
    Serial.println(results[0]);
    Serial.print("Message ID: ");
    Serial.println(results[1]);
    Serial.print("Control Mode: ");
    Serial.println(results[2]);
    Serial.print("Path Mode: ");
    Serial.println(results[3]);
    Serial.print("Lights: ");
    Serial.println(results[4]);
    Serial.print("Emergency: ");
    Serial.println(results[5]);
    Serial.print("Tool Type: ");
    Serial.println(results[6]);
    Serial.println();
}



void loop() {
    printer();
    delay(1000);
}
