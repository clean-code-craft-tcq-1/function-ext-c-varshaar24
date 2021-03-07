

/****************************************************/
/* Macros                                           */
/****************************************************/

#define TEMPERATURE_UL 45
#define TEMPERATURE_LL 0
#define SOC_UL 80
#define SOC_LL 20
#define CHARGERATE_UL 0.8

#define WARNING_LIMIT_IN_PERCENT (float)5



int CheckTemperatureInRange(float ParamVal_f, float UL, float LL);
int CheckSocInRange(float ParamVal_f, float UL, float LL);
int CheckChargeRateInRange(float ParamVal_f, float UL);
