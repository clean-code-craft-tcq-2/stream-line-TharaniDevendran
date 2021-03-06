#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"

void GetSensorDataFromConsole(float* Temperature, float* SOC, float* ChargeRate)
{
  int readingIndex = 0;
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    scanf("%f ,%f ,%f",&Temperature[readingIndex],&SOC[readingIndex],&ChargeRate[readingIndex]);
  }
  
}

float GetParameterMaxReadingValue(float *BMSParameter)
{
  int readingIndex;
  float MaxReadingValue = BMSParameter[0];
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    if(BMSParameter[readingIndex] > MaxReadingValue)
    {
      MaxReadingValue = BMSParameter[readingIndex];
    }
  }
  
  return MaxReadingValue;
}

float GetParameterMinReadingValue(float *BMSParameter)
{
  int readingIndex;
  float MinReadingValue = BMSParameter[0];
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    if(BMSParameter[readingIndex] < MinReadingValue)
    {
      MinReadingValue = BMSParameter[readingIndex];
    }
  }
  
  return MinReadingValue;
}

float GetParameterSMAValue(float *BMSParameter)
{
  float SMAValue = 0.0;
  float Sum = 0.0;
  int readingIndex = 0;
  for(readingIndex = (NO_OF_READINGS-5); readingIndex < NO_OF_READINGS; readingIndex++)
  {
    Sum += BMSParameter[readingIndex];
  }
  
  SMAValue = Sum/5;
  
  return SMAValue;
  
}

void PrintReceivedDataOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA)
{
  int readingIndex = 0;
  printf("Data received from sender\n");
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    printf("%f\n",BMSParameter[readingIndex]);
  }
  printf("Max value: %f, Min value: %f, SMA: %f\n",MaxValue,Minvalue,SMA);
  
}

void BMSReceiver(float* Temperature, float* SOC, float* ChargeRate)
{
  GetSensorDataFromConsole(Temperature,SOC,ChargeRate);
  PrintReceivedDataOnConsole(Temperature,GetParameterMaxReadingValue(Temperature),GetParameterMinReadingValue(Temperature),GetParameterSMAValue(Temperature));
  PrintReceivedDataOnConsole(SOC,GetParameterMaxReadingValue(SOC),GetParameterMinReadingValue(SOC),GetParameterSMAValue(SOC));
  PrintReceivedDataOnConsole(ChargeRate,GetParameterMaxReadingValue(ChargeRate),GetParameterMinReadingValue(ChargeRate),GetParameterSMAValue(ChargeRate));
}
