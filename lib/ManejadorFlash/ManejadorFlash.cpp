#include "ManejadorFlash.h"

ManejadorFlash::ManejadorFlash()
{
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("Failed to initialise EEPROM");
  }
  this->definirAddress();
}

byte ManejadorFlash::leerID()
{
  bool estaConfigurado = EEPROM.readBool(this->addressIDConfigurado);
  delay(100);
  if (estaConfigurado)
  {
    byte ID = EEPROM.readByte(this->addressID);
    delay(100);
    return ID;
  }
  return 0;
}

void ManejadorFlash::grabarID(byte ID)
{
  EEPROM.writeBool(this->addressIDConfigurado, true);
  EEPROM.commit();
  delay(10);
  EEPROM.writeByte(this->addressID, ID);
  EEPROM.commit();
  delay(10);
}

void ManejadorFlash::reiniciarConfiguracion()
{
  EEPROM.writeBool(this->addressIDConfigurado, false);
  EEPROM.commit();
  delay(10);
}

int ManejadorFlash::getAddress(int noOfBytes)
{
  int availableaddress = _nextAvailableaddress;
  _nextAvailableaddress += noOfBytes;

  return availableaddress;
}

void ManejadorFlash::definirAddress()
{
  this->addressIDConfigurado = getAddress(sizeof(byte));
  this->addressID = getAddress(sizeof(byte));
}