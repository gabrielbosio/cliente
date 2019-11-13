#include <Arduino.h>

#include "DisplayHelper.h"

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


// display_number: Display number from 00 to 99
void DisplayHelper::display_number(int number)
{
    int first_digit = floor(number / 10);
    int second_digit = number % 10;
    display(vector_number[first_digit], 0);
    delay(5);
    display(vector_number[second_digit], 1);
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