#include <WiFi.h>

const char* ssid = "Mohamed-iPhone";  // Replace with your WiFi network name
const char* password = "Loggain97";  // Replace with your WiFi password
const char* host = "172.20.10.1";  // Replace with your server's IP address
const uint16_t port = 12345;  // The port on which your server is listening

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to the WiFi network");
  Serial.print("Local IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Connection to host failed");
    delay(5000);  // Wait 5 seconds before retrying
    return;
  }

  int sensorValue = analogRead(A1); // Read the analog value from pin A0.


  String brakeData = "1038"; // sensorValue
  client.print("brakeData=" + brakeData);
  Serial.println("brakeData=" + brakeData);
  client.stop();
}