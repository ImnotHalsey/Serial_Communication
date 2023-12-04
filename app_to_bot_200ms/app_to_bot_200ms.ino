//  Bot To APP --> Mode 2000ms communication 
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);
struct SensorData {long timestamp;int Message_ID;int tool_type;int crop_mode;int crop_age;int row_spacing;int blade_size;int depth;};

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

// Class for all communication processing ...
class SensorDataProcessor {
public:
        long get_timestamp() { return 0; }
        int get_Message_ID() { return random(1001, 1099);}
        int get_tool_type() { return random(0, 3);}
        int get_crop_mode() { return random(0, 6);}
        int get_crop_age() { return random(0, 4);}
        int get_row_spacing() { return random(0, 3);}
        int get_blade_size() { return random(0, 3);}
        int get_depth() { return random(0, 4);}};


SensorData ArrayMaker() {
    SensorDataProcessor dataProcessor;
    SensorData data;

    data.timestamp = dataProcessor.get_timestamp();
    data.Message_ID = dataProcessor.get_Message_ID();
    data.tool_type = dataProcessor.get_tool_type();
    data.crop_mode = dataProcessor.get_crop_mode();
    data.crop_age = dataProcessor.get_crop_age();
    data.row_spacing = dataProcessor.get_row_spacing();
    data.blade_size = dataProcessor.get_blade_size();
    data.depth = dataProcessor.get_depth();

    return data;
}


void sendData(const SensorData & data) {
    mySerial.write((uint8_t*)&data, sizeof(SensorData));

    // Print individual values without a custom print function --> Remove this in prod !
    Serial.println("Sent data as an array");
    Serial.print("get_TimeStamp: "); Serial.println(data.timestamp);
    Serial.print("get_Message_ID: "); Serial.println(data.Message_ID);
    Serial.print("get_tool_type: "); Serial.println(data.tool_type);
    Serial.print("get_crop_mode: "); Serial.println(data.crop_mode);
    Serial.print("get_crop_age: "); Serial.println(data.crop_age);
    Serial.print("get_row_spacing: "); Serial.println(data.row_spacing);
    Serial.print("get_blade_size: "); Serial.println(data.blade_size);
    Serial.print("get_depth: "); Serial.println(data.depth);

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
                      // -> get_tool_type: 2
                      // -> get_crop_mode: 1
                      // -> get_crop_age: 0
                      // -> get_row_spacing: 1
                      // -> get_blade_size: 0
                      // -> get_depth: 6