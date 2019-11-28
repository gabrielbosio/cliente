#ifndef MENSAJERO_H
#define MENSAJERO_H

#include "ControladorAlertas.h"
#include "Display.h"
#include "MatrizLeds.h"
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>

class Mensajero
{
public:
    Mensajero(byte id, ControladorAlertas *controladorAlertas, Display *display,
              MatrizLeds *matrizLeds);
    void asignarId(byte id);
    byte id();
    void notificarPedidoMozo();
    void notificarAck();
    void notificarConsultaEspera();
    void notificarRegistro();

private:
    byte _id;
    ControladorAlertas *controladorAlertas;
    Display *display;
    MatrizLeds *matrizLeds;
    HTTPClient cliente;
    AsyncWebServer *servidor;
    void inicializarServidor();
    void intentarConectarseAServidor();
    bool esNumero(String parametro);
};

#endif