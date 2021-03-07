#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "BMS_Types.h"
#include "BMS_Display.h"

static int batteryIsOk(float temperature, float soc, float chargeRate)
{

    bool Temperr_b;
    bool Socerr_b;
    bool Rateerr_b;
    int Ret;

    if(0==CheckTemperatureInRange(temperature,(float)TEMPERATURE_UL,(float)TEMPERATURE_LL))
    {
        return 0;
    }
    else if(0==CheckSocInRange(soc,(float)SOC_UL,(float)SOC_LL))
    {
        return 0;
    }
    else if(0==CheckChargeRateInRange(chargeRate,(float)CHARGERATE_UL))
    {
        return 0;
    }
    else
    {
        DisplayBatteryFineStatus();
        return 1;
    }

  return Ret;
}

int main()
{

    while(SelectLanguage());

    assert(batteryIsOk(25, 70, 0.7));
   assert(!batteryIsOk(-1, 80, 0));
   assert(!batteryIsOk(50, 85, 0));
   assert(!batteryIsOk(25, 15, 0));
   assert(!batteryIsOk(40, 85, 0));
   assert(!batteryIsOk(40, 80, 0.9));
  return 0;
}
