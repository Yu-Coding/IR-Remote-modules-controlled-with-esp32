// Include the necessary library
#include <HardwareSerial.h>

// Define the serial port (using Serial2, change to Serial0 or Serial1 if needed)
HardwareSerial mySerial(2);

// Define the pin numbers for TX and RX
#define TXD_PIN 1  // TX pin for ESP32 (connected to P3.0 RXD of STC8G1K17)
#define RXD_PIN 3  // RX pin for ESP32 (connected to P3.1 TXD of STC8G1K17)

// Time interval between transmissions (20 minnutes)
const unsigned long interval = 20*60*1000;   //Minutes*Second*Millionseocnd
unsigned long previousMillis = 0;

void setup() {
  // Start serial communication at a baud rate of 115200 (Must match the aud rate of the STC8G1K17)
  mySerial.begin(115200, SERIAL_8N1, RXD_PIN, TXD_PIN);

  // Send the signal transmit according to IR remote manual when it starts
  uint8_t data[] = {0x68, 0x08, 0x00, 0xFF, 0x12, 0x00, 0x11, 0x16};  

    // Send the data over the serial port
  mySerial.write(data, sizeof(data));

}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Check if set timer have passed
  if (currentMillis - previousMillis >= interval) {
    // Update the previousMillis variable
    previousMillis = currentMillis;

    // Send the hexadecimal data to transmit IR signal according to IR remote manual
    uint8_t data[] = {0x68, 0x08, 0x00, 0xFF, 0x12, 0x00, 0x11, 0x16};

    // Send the data over the serial port
    mySerial.write(data, sizeof(data));

    // Print confirmation to the Serial Monitor
    Serial.print("Sent data to STC8G1K17: ");
    for (int i = 0; i < sizeof(data); i++) {
      Serial.print(data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  
  }
}

