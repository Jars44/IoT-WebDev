#include <WiFi.h>
#include <WebServer.h>

WebServer server(80); 

const int* ssid = "Jezina light 1"
const int* password = "12345678"

const int espLed = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 19;
const int ledPin4 = 22;

bool tidurLedState = false;
bool tamuLedState = false;
bool makanLedState = false;
bool keluargaLedState = false;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  WiFi.begin(ssid, password);
  Serial.print("connecting to WiFi...")

  while (WiFi.status() != WL_CONNECTED){
    digitalWrite(espLed, LOW);
    delay(1000);
    Serial.print(".")
  }
  digitalWrite(espLed, HIGH)
  Serial.println("")
  Serial.println("connected to wifi network!");
  Serial.println(WiFi.localIP);

  server.on("/tidur", HTTP_GET, getTidurLed);
  server.on("/tamu", HTTP_GET, getTamuLed);
  server.on("/makan", HTTP_GET, getMakanLed);
  server.on("/keluarga", HTTP_GET, getKeluargaLed);

  server.on("/tidur", HTTP_POST, getTidurLed);
  server.on("/tamu", HTTP_POST, getTamuLed);
  server.on("/makan", HTTP_POST, getMakanLed);
  server.on("/keluarga", HTTP_POST, getKeluargaLed);

  server.begin();
  Serial.println("server started...");
}

void loop() {
  server.handleClient();  
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