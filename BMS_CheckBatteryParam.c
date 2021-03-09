
#include "BMS_Display.h"

static int CheckParameterUpperLimit(Parameter_tst ParamProperties_st,float ParamVal_f)
{
    int returnVal_u8=0;
    
    if(ParamVal_f > ParamProperties_st.UL)
    {
        returnVal_u8 = 1;
    }
    else
    {
        if(ParamVal_f > ParamProperties_st.HigherWarningLimit)
        {
            DisplayParameterULWarningStatus(ParamProperties_st.ParamName,ParamVal_f);
        }
    }
    return returnVal_u8;

}

static int CheckParameterLowerLimit(Parameter_tst ParamProperties_st,float ParamVal_f)
{
    int returnVal_u8=0;

    returnVal_u8 = ParamVal_f < ParamProperties_st.LL ? 1 : 0;

    if((returnVal_u8==0) && (ParamVal_f <= ParamProperties_st.LowerWarningLimit))
    {
        DisplayParameterLLWarningStatus(ParamProperties_st.ParamName,ParamVal_f);
    }

    return returnVal_u8;

}

int CheckTemperatureInRange(float ParamVal_f, float UL, float LL)
{
    Parameter_tst TemperatureProperties_st;
    int returnVal_u8 = 1;

    TemperatureProperties_st.ParamName = "Temperature";
    TemperatureProperties_st.UL = TEMPERATURE_UL;
    TemperatureProperties_st.LL = TEMPERATURE_LL;
    TemperatureProperties_st.LowerWarningLimit = (LL+((5*TEMPERATURE_LL)/100));
    TemperatureProperties_st.HigherWarningLimit = (UL-((5*TEMPERATURE_UL)/100)) ;

    if( CheckParameterLowerLimit(TemperatureProperties_st,ParamVal_f))
    {
        DisplayParameterLLErrorStatus(TemperatureProperties_st.ParamName ,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(TemperatureProperties_st,ParamVal_f))
    {
        DisplayParameterULErrorStatus(TemperatureProperties_st.ParamName ,UL);
        returnVal_u8 = 0;
    }
    else
    {

    }

    return returnVal_u8;
}

int CheckSocInRange(float ParamVal_f, float UL, float LL)
{
    Parameter_tst SOCProperties_st;
    int returnVal_u8 = 1;

    SOCProperties_st.ParamName = "State of Charge";
    SOCProperties_st.UL = SOC_UL;
    SOCProperties_st.LL = SOC_LL;
    SOCProperties_st.LowerWarningLimit = (LL+((5*SOC_LL)/100));
    SOCProperties_st.HigherWarningLimit = (UL-((5*SOC_UL)/100)) ;

    if( CheckParameterLowerLimit(SOCProperties_st,ParamVal_f))
    {
        DisplayParameterLLErrorStatus(SOCProperties_st.ParamName ,LL);
        returnVal_u8 = 0;
    }
    else if(CheckParameterUpperLimit(SOCProperties_st,ParamVal_f))
    {
        DisplayParameterULErrorStatus(SOCProperties_st.ParamName ,UL);
        returnVal_u8 = 0;
    }
    else
    {

    }
    return returnVal_u8;
}

int CheckChargeRateInRange(float ParamVal_f, float UL)
{
    Parameter_tst CRProperties_st;
    int returnVal_u8 = 1;

    CRProperties_st.ParamName = "Charge Rate";
    CRProperties_st.UL = CHARGERATE_UL;
    CRProperties_st.LL = 0;
    CRProperties_st.LowerWarningLimit = 0;
    CRProperties_st.HigherWarningLimit = (UL-((5*CHARGERATE_UL)/100)) ;

    if(CheckParameterUpperLimit(CRProperties_st,ParamVal_f))
    {
        DisplayParameterULErrorStatus(CRProperties_st.ParamName ,UL);
        returnVal_u8 = 0;
    }

    return returnVal_u8;
}
