class DisplayHelper
{
private:
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

public:
    // DisplayHelper receive from a to g segments pin number and mux 0 - 1 for control displays
    DisplayHelper(int a, int b, int c, int d, int e, int f, int g, int mux_0, int mux_1);
    void display_number(int number);
    void display(int* number, int mux);
};