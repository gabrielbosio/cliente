#include "Mensajero.h"
#include <WiFi.h>

Mensajero::Mensajero(int id, ControladorAlertas* controladorAlertas, Display* display,
                     MatrizLeds* matrizLeds) :
    _id(id), controladorAlertas(controladorAlertas), display(display), matrizLeds(matrizLeds) {

    servidor = new AsyncWebServer(80);
    Serial.begin(115200);
    intentarConectarseAServidor();
    inicializarServidor();
    notificarRegistro();
}

void Mensajero::asignarId(int id) {
    _id = id;
}

int Mensajero::id() {
    return _id;
}

void Mensajero::notificarPedidoMozo() {
    String ruta = "http://192.168.1.2/pedir_mozo?cliente=" + String(_id);
    cliente.begin(ruta);
    display->asignarEstado(CARGANDO);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
    if (codigoRespuesta < 0 || codigoRespuesta >= 400) {
        display->asignarEstado(STAND_BY);
    }
}

void Mensajero::notificarAck() {
    String ruta = "http://192.168.1.2/confirmar_recepcion_mesa_lista?cliente=" + String(_id);
    cliente.begin(ruta);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
}

void Mensajero::notificarConsultaEspera() {
    String ruta = "http://192.168.1.2/preguntar_espera?cliente=" + String(_id);
    cliente.begin(ruta);
    display->asignarEstado(CARGANDO);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
    if (codigoRespuesta < 0 || codigoRespuesta >= 400) {
        display->asignarEstado(STAND_BY);
    }
}

void Mensajero::inicializarServidor() {
    servidor->on("/ping", HTTP_GET, [](AsyncWebServerRequest* request){
        request->send(200, "text/plain", "pong");
    });

    servidor->on("/notificar_recepcion_solicitud_mozo", HTTP_GET, [=](AsyncWebServerRequest* request){
        display->asignarEstado(STAND_BY);
        request->send(200, "text/plain", "Notificacion recibida");
    });

    servidor->on("/notificar_espera", HTTP_GET, [=](AsyncWebServerRequest* request){
        AsyncWebParameter* parametroMinutos = request->getParam(0);

        if (parametroMinutos != NULL && parametroMinutos->name() == "minutos" &&
            esNumero(parametroMinutos->value())) {

            int minutos = parametroMinutos->value().toInt();
            if (minutos >= 0 && minutos <= 99) {
                display->asignarNumero(minutos);
                display->asignarEstado(MOSTRANDO_NUMERO);
                request->send(200, "text/plain", "Notificacion recibida");
            }
        }
        request->send(400, "text/plain", "Error de parametros");
    });

    servidor->on("/notificar_mesa_lista", HTTP_GET, [=](AsyncWebServerRequest* request){
        matrizLeds->encender();
        controladorAlertas->encender();
        request->send(200, "text/plain", "Notificacion recibida");
    });

    servidor->begin();
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
    String ruta = "http://192.168.1.2/registrarse?id=" + String(_id) + "&ip=" + ip;
    Serial.print("Enviando ");
    Serial.println(ruta);
    cliente.begin(ruta);
    int codigoRespuesta = cliente.GET();
    cliente.end();
    Serial.print("Codigo de respuesta: ");
    Serial.println(codigoRespuesta);
}

bool Mensajero::esNumero(String parametro) {
    for (int i = 0; i < parametro.length(); i++) {
        char caracter = parametro.charAt(i);
        
        if (!isDigit(caracter)) {
            return false;
        }
    }

    return true;
}
