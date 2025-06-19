#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1  // -1 si no se usa un pin de reset
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Inicializa la pantalla
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Dirección I2C común: 0x3C
    Serial.println("No se pudo inicializar la pantalla OLED");
    while (true); // Se detiene aquí si falla
  }

  // Mostrar "Hello"
  display.clearDisplay();
  display.setTextSize(2);             // Tamaño de texto (1 = pequeño, 2 = mediano, etc.)
  display.setTextColor(WHITE);        // Color del texto
  display.setCursor(10, 25);          // Posición en pantalla (x, y)
  display.println("Hello World");     // Texto a mostrar
  display.display();                  // Envía al display
}

void loop() {
  // Nada en el loop
}