
#include "BMS_Display.h"

static int CheckParameterWarningLowerLimit(float Paramvalue_f, float ParamLowerLimit_f)
{
    int returnVal_u8=0;
    int temp;

    temp =  ((5 * ParamLowerLimit_f) / 100);
    returnVal_u8 = Paramvalue_f <= ParamLowerLimit_f+temp ? 1 : 0;

    return returnVal_u8;

}

static int CheckParameterWarningUpperLimit(float Paramvalue_f, float ParamUpperLimit_f)
{
    int returnVal_u8=0;
    int temp;

    temp =  ((5 * ParamUpperLimit_f) / 100);
    returnVal_u8 = Paramvalue_f > ParamUpperLimit_f-temp ? 1 : 0;

    return returnVal_u8;

}

static int CheckParameterUpperLimit(float Paramvalue_f, float ParamUpperLimit_f)
{
    int returnVal_u8=0;

    returnVal_u8 = Paramvalue_f > ParamUpperLimit_f ? 1 : 0;

    return returnVal_u8;

}

static int CheckParameterLowerLimit(float Paramvalue_f, float ParamLowerLimit_f)
{
    int returnVal_u8=0;

    returnVal_u8 = Paramvalue_f < ParamLowerLimit_f ? 1 : 0;

    return returnVal_u8;

}

int CheckTemperatureInRange(float ParamVal_f, float UL, float LL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "Temperature";

    returnVal_u8 = CheckAndDispalyTempearture(BatterParameterName,ParamVal_f,LL,UL);

    if( CheckParameterLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLErrorStatus(BatterParameterName,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterWarningLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLWarningStatus(BatterParameterName,ParamVal_f);

    }
    else if(CheckParameterWarningUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULWarningStatus(BatterParameterName,ParamVal_f);

    }

    return returnVal_u8;
}

int CheckSocInRange(float ParamVal_f, float UL, float LL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "State of Charge";

    if( CheckParameterLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLErrorStatus(BatterParameterName,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterWarningLowerLimit(ParamVal_f,LL))
    {
        DisplayParameterLLWarningStatus(BatterParameterName,ParamVal_f);

    }
    else if(CheckParameterWarningUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULWarningStatus(BatterParameterName,ParamVal_f);

    }
    return returnVal_u8;
}

int CheckChargeRateInRange(float ParamVal_f, float UL)
{
    int returnVal_u8 = 1;
    char *BatterParameterName = "Charge Rate";

    if(CheckParameterUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULErrorStatus(BatterParameterName,UL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterWarningUpperLimit(ParamVal_f,UL))
    {
        DisplayParameterULWarningStatus(BatterParameterName,ParamVal_f);

    }

    return returnVal_u8;
}
