#include <stdio.h>
#include "BMS_Types.h"


static int Language_u8;

int SelectLanguage()
{
    int Ret;

    printf("Please select language to read battery status.Enter 1 for english or 2 for German\n"
            "Bitte wählen Sie die Sprache aus, um den Batteriestatus zu lesen. Geben Sie 1 für Englisch oder 2 für Deutsch ein \n");

    scanf("%d",&Language_u8);

    Ret = (Language_u8 == 1 || Language_u8 == 2) ? 0 : 1;

    return Ret;
}

void DisplayBatteryFineStatus()
{
    Language_u8 == 1  ? printf("Battery Fine!\n") :  printf("Batterie gut !\n");
}
void DisplayParameterLLErrorStatus(char * BatterParameterName_p ,float ParamLimit_f)
{
   ( Language_u8 == 1  ? printf("Alert: %s  is less than %f !\n",BatterParameterName_p,ParamLimit_f) :
                         printf("aufmerksam: %s  ist weniger als %f !\n",BatterParameterName_p,ParamLimit_f)) ;
}
void DisplayParameterULErrorStatus(char * BatterParameterName_p,float ParamLimit_f)
{
    Language_u8 == 1 ?printf("Alert: %s  is greater than %f!\n",BatterParameterName_p,ParamLimit_f) :
            printf("aufmerksam: %s  ist größer als than %f!\n",BatterParameterName_p,ParamLimit_f);
}
void DisplayParameterLLWarningStatus(char * BatterParameterName_p ,float ParamVal_f)
{
    Language_u8 == 1 ? printf("Warning: %s  is  %f.Approaching lower limit  !\n",BatterParameterName_p,ParamVal_f) :
            printf("Die Warnung: %s  ist  %f.Annäherung an die Untergrenze!\n",BatterParameterName_p,ParamVal_f);
}
void DisplayParameterULWarningStatus(char * BatterParameterName_p ,float ParamVal_f)
{
    Language_u8 == 1 ? printf("Warning: %s  is  %f.Approaching higher limit  !\n",BatterParameterName_p,ParamVal_f) :
            printf("Die Warnung: %s  ist  %f.Annäherung an die Obergrenze!\n",BatterParameterName_p,ParamVal_f);
}

