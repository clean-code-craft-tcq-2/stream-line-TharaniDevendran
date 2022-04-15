#include "BatteryReadingSender.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void printOnConsole(float temperature, float SOC, float CR){
    printf(" Temperature : %.2f , State of Charge : %.2f , Charge Rate : %.2f \n",temperature,SOC,CR);
}

void ReadBatteryReadingsfromFile(float* Temperature, float* SOC, float* ChargeRate)
{
    float Temperature_reading, SOC_reading,CR_reading;
    FILE* fp= fopen("./Battery_Reading.txt","r");  

    if (NULL == fp)
    {
        printf("file can't be opened \n");
    }
    else 
    {
        for(int i=0;fscanf(fp, "%f\t%f\t%f\n", &Temperature_reading,&SOC_reading,&CR_reading)!=EOF ;i++)
        {
            *(Temperature+i) = Temperature_reading;
            *(SOC+i)  = SOC_reading;
            *(ChargeRate+i)   = CR_reading;
        }
    }
    fclose(fp);  
}

void SendBatteryReadingsToConsole(float* Temperature, float* SOC, float* ChargeRate)
{
    float Temperature_ToPrint, SOC_ToPrint, CR_ToPrint;
    for(int i = 0; i<NO_OF_READINGS;i++)
    {
        Temperature_ToPrint = *(Temperature+i);
        SOC_ToPrint = *(SOC+i);
        CR_ToPrint = *(ChargeRate+i);
        printOnConsole(Temperature_ToPrint, SOC_ToPrint, CR_ToPrint);
    }
}

void BatteryReadingSender(float* Temperature, float* SOC, float* ChargeRate)
{
  ReadBatteryReadingsfromFile(Temperature,SOC,ChargeRate);
  SendBatteryReadingsToConsole(Temperature,SOC,ChargeRate);
}
