#include <WiFi.h>

const char* ssid = "Mohamed-iPhone";  // Replace with your WiFi network name
const char* password = "Loggain97";  // Replace with your WiFi password
const char* host = "172.20.10.1";  // Replace with your server's IP address
const uint16_t port = 12345;  // The port on which your server is listening

void setup() {
  Serial.begin(115200);
  // WiFi.begin(ssid, password);

  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.println("Connecting to WiFi...");
  // }

  // Serial.println("Connected to the WiFi network");
  // Serial.print("Local IP address: ");
  // Serial.println(WiFi.localIP());
}

void loop() {
   int sensorValue = analogRead(A0); // Read the analog value from pin A0.
  Serial.println(sensorValue); // Print the value to the Serial Monitor.
  delay(200); // Wait 200 milliseconds before reading again.
  // WiFiClient client;

  // if (!client.connect(host, port)) {
  //   Serial.println("Connection to host failed");
  //   delay(5000);  // Wait 5 seconds before retrying
  //   return;
  // }

  // String brakeData = "1037"; // Replace this with your actual brake data
  // String pedalDataR = "1038";
  // String pedalDataL = "1036";
  // client.print(brakeData + "-" + pedalDataR + "-" + pedalDataL);
  // Serial.println(brakeData + "-" + pedalDataR + "-" + pedalDataL);
  // client.stop();
}