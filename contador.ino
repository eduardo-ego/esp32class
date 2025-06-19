#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Variables del contador
unsigned long lastUpdate = 0;
int contador = 0;

void setup() {
  Serial.begin(115200);

  // Inicializa la pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Error al iniciar pantalla OLED");
    while (true);
  }

  // Mostrar mensaje inicial
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.println("Contador:");
  display.display();
  delay(1000); // Esperar un segundo antes de iniciar
}

void loop() {
  unsigned long currentTime = millis();

  // Actualiza el contador cada 1000 ms (1 segundo)
  if (currentTime - lastUpdate >= 1000) {
    lastUpdate = currentTime;
    contador++;

    // Mostrar contador en pantalla
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(10, 10);
    display.println("Contador:");
    display.setCursor(40, 40);
    display.println(contador);
    display.display();
  }
}