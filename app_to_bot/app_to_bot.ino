//  Bot To APP --> Mode 50- 100ms communication 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);
struct SensorData {
    long timestamp;
    int Message_ID;
    int Control_mode;
    int path_mode;
    int lights;
    int Emergency;
    int tool_type;
};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

// Class for all communication processing ...
class SensorDataProcessor {
public:
  long get_timestamp() { return 0; }
  int get_Message_ID() { return random(1001, 1099);}
  int get_Control_mode() { return random(0, 3);}
  int get_path_mode() { return random(0, 2);}
  int get_lights() { return random(0, 2);}
  int get_Emergency() { return random(0, 2);}
  int tool_type() { return random(0, 7);}
};


SensorData ArrayMaker() {
    SensorDataProcessor dataProcessor;
    SensorData data;

    data.timestamp = dataProcessor.get_timestamp();
    data.Message_ID = dataProcessor.get_Message_ID();
    data.Control_mode = dataProcessor.get_Control_mode();
    data.path_mode = dataProcessor.get_path_mode();
    data.lights = dataProcessor.get_lights();
    data.Emergency = dataProcessor.get_Emergency();
    data.tool_type = dataProcessor.tool_type();

    return data;
}


void sendData(const SensorData & data) {
    mySerial.write((uint8_t*)&data, sizeof(SensorData));

    // Print individual values without a custom print function --> Remove this in prod !
    Serial.println("Sent data as an array");
    Serial.print("get_TimeStamp: "); Serial.println(data.timestamp);
    Serial.print("get_Message_ID: "); Serial.println(data.Message_ID);
    Serial.print("get_Control_mode: "); Serial.println(data.Control_mode);
    Serial.print("get_path_mode: "); Serial.println(data.path_mode);
    Serial.print("get_lights: "); Serial.println(data.lights);
    Serial.print("get_Emergency: "); Serial.println(data.Emergency);
    Serial.print("tool_type: "); Serial.println(data.tool_type);

}

void loop() {
    SensorData randomData = ArrayMaker();
    sendData(randomData);
    delay(1000);
}
                    // Sending code End!

                    //  -- > Base code version :: 1

                    //  --> Expected printed output 
                    
                              // -> Sent data as an array
                              // -> get_TimeStamp: 0
                              // -> get_Message_ID: 1037
                              // -> get_Control_mode: 0
                              // -> get_path_mode: 1
                              // -> get_lights: 0
                              // -> get_Emergency: 0
                              // -> tool_type: 2