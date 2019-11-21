#ifndef ACCION_SWITCH_H
#define ACCION_SWITCH_H

class AccionSwitch {
    public:
        virtual ~AccionSwitch() {};
        virtual void ejecutar(int estadoActualPinSwitch, int estadoAnteriorPinSwitch) = 0;
};

#endif