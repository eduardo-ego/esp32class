# Taller ESP32 – Fundamentos Prácticos con OLED y Servidor Web

## 🧠 Objetivo del taller

Aprender a utilizar el ESP32 desde cero mediante ejercicios prácticos progresivos, comprendiendo su funcionamiento, estructura y posibilidades de interacción con periféricos como pantallas OLED, así como sus capacidades de red mediante la implementación de un servidor web.

---

## ✅ Herramientas necesarias

- Placa ESP32 (WROOM-32U o similar)
- Pantalla OLED (I2C, SSD1306, 0.96")
- Cable USB
- Arduino IDE o PlatformIO
- Librerías:
  - `Adafruit SSD1306`
  - `Adafruit GFX`
  - `ESPAsyncWebServer`
  - `AsyncTCP`
  - `SPIFFS` (para servir archivos como imágenes)

---

## 🧪 Ejercicios prácticos del taller

### 1. **Hello Serial (Hello World)**
Se inicia con el ejercicio clásico de programación: mostrar un mensaje en el monitor serial. Este paso permite probar la comunicación básica entre el ESP32 y la computadora, así como verificar que todo el entorno está correctamente configurado.

**Lo que se aprende:**
- Comunicación serial
- Estructura mínima de un programa para ESP32

---

### 2. **Hello Display**
En este ejercicio se utiliza la pantalla OLED para mostrar un mensaje simple. Esto introduce el manejo de periféricos I2C y el uso de librerías externas.

**Lo que se aprende:**
- Inicialización de pantalla SSD1306
- Configuración de texto en pantalla
- Uso de coordenadas y estilos

---

### 3. **Contador en pantalla**
Se muestra un contador que se incrementa automáticamente cada segundo en la pantalla OLED. Se utilizan temporizadores con `millis()` para evitar el uso de `delay()`.

**Lo que se aprende:**
- Lógica de tiempo sin bloqueo (`millis()`)
- Actualización dinámica de valores en pantalla
- Control de flujo básico

---

### 4. **Servidor web con entrada de texto**
El ESP32 se conecta a una red WiFi y levanta un servidor web con un formulario. El usuario puede enviar un texto desde su navegador, y ese texto se muestra en la pantalla OLED del dispositivo.

**Lo que se aprende:**
- Conexión WiFi
- Manejo de formularios HTML desde ESP32
- Lectura de datos web (POST)
- Mostrar datos recibidos en pantalla
- Separar el código en archivos `.h` para mantenerlo organizado (modularización)
- Servir archivos estáticos desde SPIFFS (como imágenes o HTML)

---

## 📌 Habilidades adquiridas

- Programación estructurada en C/C++ sobre ESP32
- Uso de periféricos I2C (pantalla OLED)
- Control de tiempo con `millis()`
- Construcción de servidores web embebidos
- Comunicación entre hardware y cliente web
- Gestión de archivos embebidos en microcontroladores (SPIFFS)
- Buenas prácticas de organización del código

---



