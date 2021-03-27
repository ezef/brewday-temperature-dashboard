#include "TemperatureControlFunctions.h"

void readTemperatures(){
  sensors.requestTemperatures();
  tempsensada1= sensors.getTempCByIndex(0);

  sensors2.requestTemperatures();
  tempsensada2= sensors2.getTempCByIndex(0);
}

