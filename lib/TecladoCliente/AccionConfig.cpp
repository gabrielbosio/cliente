#include <Arduino.h>
#include "AccionConfig.h"

AccionConfig::AccionConfig(TecladoCliente *tecladoCliente) : tecladoCliente(tecladoCliente) {}

void AccionConfig::ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) {
  if (estadoActualPinSwitch == HIGH) {
    tecladoCliente->configurar(CONFIG, CONFIG, CONFIG, NORMAL);
  } else {
    tecladoCliente->configurar(NORMAL, NORMAL, NORMAL, NORMAL);
  }
}