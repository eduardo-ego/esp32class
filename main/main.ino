#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "oled_display.h"
#include "web_server.h"

// WiFi
const char* ssid = "test";  // Cambia por tu SSID
const char* password = "12345678";

// Global text value
String inputText = "";

void setup() {
  Serial.begin(115200);
  initOLED();  // Inicializa pantalla
  displayText("Esperando WiFi");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");
  Serial.println(WiFi.localIP());
  displayText("WiFi OK");

  // Inicia servidor web y pasa el puntero al texto a modificar
  initWebServer(&inputText);
}

void loop() {
  // Mostrar en pantalla el texto recibido por web
  displayText(inputText);
  delay(100);  // Evita parpadeo excesivo
}