#include <WiFi.h>
#include <WebServer.h>

WebServer server(80); 

const char* ssid = "Jezina light 1";
const char* password = "12345678";

const int espLed = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;
const int ledPin4 = 22;

bool tidurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;
bool keluargaLedState = false;

// Tambahkan variabel untuk kedip espLed
unsigned long previousMillis = 0; // Waktu terakhir espLed berubah
const long interval = 1000;       // Interval waktu 1 detik
bool espLedState = false;         // Status kedip espLed

void setup() {
  Serial.begin(115200);

  pinMode(espLed, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);

  WiFi.begin(ssid, password);
  Serial.print("connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED){
    digitalWrite(espLed, LOW);
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("connected to wifi network!");
  Serial.println(WiFi.localIP());

  server.on("/tidur", HTTP_GET, getTidurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);
  server.on("/keluarga", HTTP_GET, getKeluargaLed);

  server.on("/tidur", HTTP_POST, setTidurLed);
  server.on("/tamu", HTTP_POST, setTamuLed);
  server.on("/makan", HTTP_POST, setMakanLed);
  server.on("/keluarga", HTTP_POST, setKeluargaLed);

  server.begin();
  Serial.println("server started...");
}

void loop() {
  server.handleClient();  

  // Kedipkan espLed setiap 1 detik
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    espLedState = !espLedState; // Toggle status LED
    digitalWrite(espLed, espLedState ? HIGH : LOW);
  }
}

void setTidurLed() {
  tidurLedState = !tidurLedState;
  digitalWrite(ledPin1, tidurLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tidurLedState ? "ON" : "OFF");
}

void setTamuLed() {
  tamuLedState = !tamuLedState;
  digitalWrite(ledPin2, tamuLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void setMakanLed() {
  makanLedState = !makanLedState;
  digitalWrite(ledPin3, makanLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void setKeluargaLed() {
  keluargaLedState = !keluargaLedState;
  digitalWrite(ledPin4, keluargaLedState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", keluargaLedState ? "ON" : "OFF");
}

void getTidurLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tidurLedState ? "ON" : "OFF");
}

void getTamuLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", tamuLedState ? "ON" : "OFF");
}

void getMakanLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", makanLedState ? "ON" : "OFF");
}

void getKeluargaLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", keluargaLedState ? "ON" : "OFF");
}