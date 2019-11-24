#include "ControladorAlertas.h"

ControladorAlertas::ControladorAlertas(){
    ledcSetup(CANAL_PWM, FRECUENCIA_BUZZER_OFF, RESOLUCION_PWM);
}

void ControladorAlertas::encender(){
    ledcAttachPin(PIN_BUZZER, FRECUENCIA_BUZZER_OFF);
    ledcWriteTone(0, FRECUENCIA_BUZZER_ON);
}

void ControladorAlertas::apagar() {
    ledcWriteTone(0, FRECUENCIA_BUZZER_OFF);
    ledcDetachPin(PIN_BUZZER);
}
