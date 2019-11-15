#include "Arduino.h"
#ifndef DISPLAY_HELPER_H
#define DISPLAY_HELPER_H

class DisplayHelper
{
private:

    bool seLlamoAlDisplay;
    TaskHandle_t DisplayTask;

public:
    // DisplayHelper receive from a to g segments pin number and mux 0 - 1 for control displays
    DisplayHelper(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1);
    void display_number(int number);
    void display_stand_by();
    void display_loading();
    void display(int *number, int mux);
    void display_number_task(int number);
};

#endif
