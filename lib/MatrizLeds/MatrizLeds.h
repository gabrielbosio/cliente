#ifndef MATRIZ_LEDS_H
#define MATRIZ_LEDS_H

#include <Arduino.h>
#include <SPI.h>

// max7219 registers
#define MAX7219_REG_NOOP 0x0
#define MAX7219_REG_DIGITO_0 0x1
#define MAX7219_REG_DIGITO_1 0x2
#define MAX7219_REG_DIGITO_2 0x3
#define MAX7219_REG_DIGITO_3 0x4
#define MAX7219_REG_DIGITO_4 0x5
#define MAX7219_REG_DIGITO_5 0x6
#define MAX7219_REG_DIGITO_6 0x7
#define MAX7219_REG_DIGITO_7 0x8
#define MAX7219_REG_DECODEMODE 0x9
#define MAX7219_REG_INTENSIDAD 0xA
#define MAX7219_REG_SCANLIMIT 0xB
#define MAX7219_REG_SHUTDOWN 0xC
#define MAX7219_REG_DISPLAYTEST 0xF

class MatrizLeds
{
public:
  MatrizLeds(uint8_t csPin);
  void apagar();
  void encender();

private:
  void enviarDatos(uint8_t registro, uint8_t datos);
  uint8_t csPin;
};

#endif