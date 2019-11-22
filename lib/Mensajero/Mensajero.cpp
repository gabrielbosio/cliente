#include "Mensajero.h"
#include <WiFi.h>

Mensajero::Mensajero(int id, Display* display) : _id(id), display(display) {
    Serial.begin(115200);
    WiFi.begin("ESP32", "12345678");
    int intentos = 10;

    while (WiFi.status() != WL_CONNECTED && intentos > 0) {
        Serial.println("Conectando a servidor...");
        intentos--;
        delay(500);
    }

    Serial.println(intentos > 0 ? "Conectado" : "No se pudo conectar");
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
    display->asignarEstado(STAND_BY);
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
