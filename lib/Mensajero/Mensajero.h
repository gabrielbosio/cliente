#ifndef MENSAJERO_H
#define MENSAJERO_H

#include "Display.h"
#include <HTTPClient.h>
#include <ESPAsyncWebServer.h>

class Mensajero {
    public:
        Mensajero(int id, Display* display);
        void asignarId(int id);
        int id();
        void notificarPedidoMozo();
        void notificarAck();
        void notificarConsultaEspera();
    private:
        int _id;
        Display* display;
        HTTPClient cliente;
        AsyncWebServer* servidor;
        void inicializarServidor();
        void intentarConectarseAServidor();
        void notificarRegistro();
        bool esNumero(String parametro);
};

#endif