#include "MatrizLeds.h"

MatrizLeds::MatrizLeds(uint8_t csPin) : csPin(csPin) {
    pinMode(csPin, OUTPUT);
    SPI.begin();
    SPI.setDataMode(SPI_MODE0);
    SPI.setClockDivider(SPI_CLOCK_DIV128);
    this->enviarDatos(MAX7219_REG_SCANLIMIT, 7);
    this->enviarDatos(MAX7219_REG_DECODEMODE, 0);
    this->enviarDatos(MAX7219_REG_DISPLAYTEST, 0);
    this->enviarDatos(MAX7219_REG_INTENSIDAD, 4);
    this->enviarDatos(MAX7219_REG_SHUTDOWN, 1);
}

void MatrizLeds::enviarDatos(uint8_t registro, uint8_t datos) {
    digitalWrite(this->csPin, LOW);
    SPI.transfer(registro);
    SPI.transfer(datos);
    digitalWrite(this->csPin, HIGH);
}

void MatrizLeds::apagar() {
    for (uint8_t reg = 1; reg < 9; reg++) {
        this->enviarDatos(reg, 0);
    }
}

void MatrizLeds::encender() {
    for (uint8_t reg = 1; reg < 9; reg++) {
        this->enviarDatos(reg, 255);
    }
}