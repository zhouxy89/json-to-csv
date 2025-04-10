#include <WiFi.h>

const char* ssid = "Mohamed-iPhone";        // Your iPhone hotspot SSID
const char* password = "Loggain97";         // Your hotspot password
const char* host = "172.20.10.1";           // iPhone's current IP address on hotspot (check in app)
const uint16_t port = 12345;                // Port your Swift app is listening on

// Define analog pins for 4 FSR sensors
const int fsr1Pin = A1;
const int fsr2Pin = A2;
const int fsr3Pin = A3;
const int fsr4Pin = A4;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to the WiFi network");
  Serial.print("📡 Local IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;

  if (!client.connect(host, port)) {
    Serial.println("Connection to host failed");
    delay(5000);
    return;
  }

  // Read all FSR sensors
  int fsr1 = analogRead(fsr1Pin);
  int fsr2 = analogRead(fsr2Pin);
  int fsr3 = analogRead(fsr3Pin);
  int fsr4 = analogRead(fsr4Pin);

  // Format the data to match expected Swift structure
  String data = "fsr1=" + String(fsr1) + "&" +
                "fsr2=" + String(fsr2) + "&" +
                "fsr3=" + String(fsr3) + "&" +
                "fsr4=" + String(fsr4);

  // Send to iOS app via TCP
  client.print(data);
  Serial.println("Sent: " + data);

  client.stop();  // Close connection after sending
  delay(1000);    // Delay for stability (1 reading/sec)
}
