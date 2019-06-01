#include <SoftwareSerial.h>
#include <CapacitiveSensor.h>

SoftwareSerial BTserial(2, 3); // Digital pins 2 and 3 for bluetooth RX and TX
CapacitiveSensor cap_sensor = CapacitiveSensor(4,8); // Digital pins 4 and 8

// Holds the current available character on the BT serial stream
char bt_char = ' ';

// Initialization 
void setup() 
{
    // Initialize pins and sensors
    pinMode(LED_BUILTIN, OUTPUT);
    cap_sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);

    // Initialize serial ports
    Serial.begin(9600);
    Serial.println("Arduino Bluetooth demo is running");
    BTserial.begin(9600);
}
 
// Main program loop
void loop() {

    // Write current sensor value to bluetooth module
    long current = cap_sensor.capacitiveSensorRaw(30);
    BTserial.print(current);
    BTserial.print(':');

    delay(100); // Pause
    
    if (BTserial.available()) {

        // Turn on/off the built-in LED
        bt_char = BTserial.read();
        digitalWrite(LED_BUILTIN, (bt_char == '1') ? HIGH : LOW);
  
    }
}