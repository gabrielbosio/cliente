#include "Mensajero.h"
#include <WiFi.h>

Mensajero::Mensajero(int id, Display* display) : _id(id), display(display) {
    servidor = new AsyncWebServer(80);
    Serial.begin(115200);
    inicializarServidor();
    intentarConectarseAServidor();
    notificarRegistro();
}

void Mensajero::asignarId(int id) {
    _id = id;
}

int Mensajero::id() {
    return _id;
}

void Mensajero::notificarPedidoMozo() {
    String ruta = "192.168.1.2/pedir_mozo?cliente=" + String(_id);
    cliente.begin(ruta);
    display->asignarEstado(CARGANDO);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
}

void Mensajero::inicializarServidor() {
    servidor->on("/ping", HTTP_GET, [](AsyncWebServerRequest* request){
        request->send(200, "text/plain", "pong");
    });

    servidor->on("/notificar_recepcion_solicitud_mozo", HTTP_GET, [=](AsyncWebServerRequest* request){
        display->asignarEstado(STAND_BY);
        request->send(200, "text/plain", "Notificacion recibida");
    });
}

void Mensajero::intentarConectarseAServidor() {
    WiFi.begin("ESP32", "12345678");
    int intentos = 10;

    while (WiFi.status() != WL_CONNECTED && intentos > 0) {
        Serial.println("Conectando a servidor...");
        intentos--;
        delay(500);
    }

    Serial.println(intentos > 0 ? "Conectado" : "No se pudo conectar");
}

void Mensajero::notificarRegistro() {
    String ip = WiFi.localIP().toString();
    String ruta = "192.168.1.2/registrarse?id=" + String(_id) + "&ip=" + ip;
    Serial.print("Enviando ");
    Serial.println(ruta);
    cliente.begin(ruta);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
}
