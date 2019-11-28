#ifndef CONTROLADOR_ALERTAS_H
#define CONTROLADOR_ALERTAS_H

#include <Arduino.h>

#define CANAL_PWM 0
#define RESOLUCION_PWM 8
#define PIN_BUZZER 21
#define FRECUENCIA_BUZZER_OFF 0
#define FRECUENCIA_BUZZER_ON 2000

class ControladorAlertas
{
public:
    ControladorAlertas();
    void encender();
    void apagar();
};

#endif