#include <Arduino.h>

#include "DisplayHelper.h"

// pin definitions
int SEGMENT_A = 18;
int SEGMENT_B = 19;
int SEGMENT_C = 21;
int SEGMENT_D = 16;
int SEGMENT_E = 17;
int SEGMENT_F = 22;
int SEGMENT_G = 23;

// mux definitions
int MUX_0 = 2;
int MUX_1 = 4;

DisplayHelper::DisplayHelper(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1) {
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    pinMode(mux_0, OUTPUT);
    pinMode(mux_1, OUTPUT);

    // pin definitions
    SEGMENT_A = a;
    SEGMENT_B = b;
    SEGMENT_C = c;
    SEGMENT_D = d;
    SEGMENT_E = e;
    SEGMENT_F = f;
    SEGMENT_G = g;

    // mux definitions
    MUX_0 = mux_0;
    MUX_1 = mux_1;
    
    seLlamoAlDisplay = false;
}

// numbers definition
int zero[7] = {1, 1, 1, 1, 1, 1, 0};
int one[7] = {0, 1, 1, 0, 0, 0, 0};
int two[7] = {1, 1, 0, 1, 1, 0, 1};
int three[7] = {1, 1, 1, 1, 0, 0, 1};
int four[7] = {0, 1, 1, 0, 0, 1, 1};
int five[7] = {1, 0, 1, 1, 0, 1, 1};
int six[7] = {1, 0, 1, 1, 1, 1, 1};
int seven[7] = {1, 1, 1, 0, 0, 0, 0};
int eight[7] = {1, 1, 1, 1, 1, 1, 1};
int nine[7] = {1, 1, 1, 0, 0, 1, 1};
int* vector_number[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
int stand_by[7] = {0, 0, 0, 0, 0, 0, 1};
int loading_one[7] = {1, 1, 0, 0, 0, 0, 0};
int loading_two[7] = {0, 1, 1, 0, 0, 0, 0};
int loading_three[7] = {0, 0, 1, 1, 0, 0, 0};
int loading_four[7] = {0, 0, 0, 1, 1, 0, 0};
int loading_five[7] = {0, 0, 0, 0, 1, 1, 0};
int loading_six[7] = {1, 0, 0, 0, 0, 1, 0};
int* loading[6] = {loading_one, loading_two, loading_three, loading_four, loading_five, loading_six};
int loading_position = 0;
int loading_count = 0;

typedef struct Parametros {
    DisplayHelper *display;
    int number;
} Parametros;

Parametros parametros;

// Used to move display behaviour has paralel task into the secondary core
void display_id_number(void *pvParameters)
{
    Parametros *parametros = (Parametros*)pvParameters;
    DisplayHelper *display = parametros->display;
    int number = parametros->number;

    for (;;)
    {
    // displayHelper->display_loading();
    // displayHelper->display_stand_by();
        display->display_number_task(number);
    }
}

// display_number: Display number from 00 to 99
void DisplayHelper::display_number(int number)
{
    parametros.display = this;
    parametros.number = number;

    if (seLlamoAlDisplay) {
        vTaskDelete(DisplayTask);
    }

    seLlamoAlDisplay = true;

    // TODO - Check how we can move this to the DisplayHelper library
    xTaskCreatePinnedToCore(
      display_id_number,    /* Task function. */
      "display_id_number",      /* name of task. */
      100000,        /* Stack size of task */
      &parametros,         /* parameter of the task */
      1,            /* priority of the task */
      &DisplayTask, /* Task handle to keep track of created task */
      1);           /* pin task to core 0 */
}

void DisplayHelper::display_number_task(int number)
{
    int first_digit = floor(number / 10);
    int second_digit = number % 10;
    display(vector_number[first_digit], 0);
    delay(5);
    display(vector_number[second_digit], 1);
    delay(5);
}

// display_stand_by: Display a simple line on each 7 segments for stand by status
void DisplayHelper::display_stand_by()
{
    display(stand_by, 0);
    delay(5);
    display(stand_by, 1);
    delay(5);
}

// display_loading: Display 7 segments moving in circles like loading state
void DisplayHelper::display_loading()
{
    if (loading_count%10 == 0) {
        loading_position++;
        if (loading_position == 6) {
            loading_position = 0;
        }
    }
    loading_count++;
    display(loading[loading_position], 0);
    delay(5);
    display(loading[loading_position], 1);
    delay(5);
}

// display: get number pointer formation and digital write the pins
void DisplayHelper::display(int *number, int mux)
{
    digitalWrite(SEGMENT_A, number[0]);
    digitalWrite(SEGMENT_B, number[1]);
    digitalWrite(SEGMENT_C, number[2]);
    digitalWrite(SEGMENT_D, number[3]);
    digitalWrite(SEGMENT_E, number[4]);
    digitalWrite(SEGMENT_F, number[5]);
    digitalWrite(SEGMENT_G, number[6]);
    if (mux == 0)
    {
        digitalWrite(MUX_0, 1);
        digitalWrite(MUX_1, 0);
    }
    if (mux == 1)
    {
        digitalWrite(MUX_0, 0);
        digitalWrite(MUX_1, 1);
    }
}