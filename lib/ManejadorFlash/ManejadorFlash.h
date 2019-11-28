#ifndef MANEJADOR_FLASH_H
#define MANEJADOR_FLASH_H

#include <Arduino.h>
#include "EEPROM.h"
#define EEPROM_SIZE 64

class ManejadorFlash
{
public:
  ManejadorFlash();
  byte leerID();
  void grabarID(byte ID);
  void reiniciarConfiguracion();

private:
  int addressID;
  int addressIDConfigurado;
  int _nextAvailableaddress = 0;
  void definirAddress();
  int getAddress(int noOfBytes);
};

#endif