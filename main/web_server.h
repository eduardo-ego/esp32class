#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "SPIFFS.h"
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void initWebServer(String* sharedText) {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>OLED Input</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #f4f4f4;
      margin: 0;
      padding: 0;
      text-align: center;
    }
    .container {
      max-width: 90%;
      margin: 30px auto;
      padding: 20px;
      background-color: #ffffff;
      border-radius: 12px;
      box-shadow: 0px 2px 8px rgba(0, 0, 0, 0.15);
    }
    img.logo {
      max-width: 150px;
      margin-top: 20px;
    }
    h2 {
      color: #333;
    }
    input[type="text"] {
      width: 90%;
      padding: 15px;
      font-size: 18px;
      margin: 20px 0;
      border: 1px solid #ccc;
      border-radius: 8px;
    }
    input[type="submit"] {
      padding: 12px 25px;
      font-size: 18px;
      background-color: #611232;
      color: white;
      border: none;
      border-radius: 8px;
      cursor: pointer;
    }
    input[type="submit"]:hover {
      background-color: #0056b3;
    }
  </style>
</head>
<body>
  <img src="https://posgrados.ciateq.edu.mx/PRE-REGISTRO/images/ciateq-vertical.png" class="logo">
  <div class="container">
    <h2>Enviar texto al ESP32</h2>
    <form action="/set" method="POST">
      <input name="text" type="text" placeholder="Escribe un mensaje" required>
      <br>
      <input type="submit" value="Enviar">
    </form>
  </div>
</body>
</html>
)rawliteral";
    request->send(200, "text/html", html);
  });

  server.on("/set", HTTP_POST, [sharedText](AsyncWebServerRequest *request) {
    if (request->hasParam("text", true)) {
      *sharedText = request->getParam("text", true)->value();
      Serial.println("Texto recibido: " + *sharedText);
    }
    request->redirect("/");
  });
  server.serveStatic("/", SPIFFS, "/");
  server.begin();
}

#endif