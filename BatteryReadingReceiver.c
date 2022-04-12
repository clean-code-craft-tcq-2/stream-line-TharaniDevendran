#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"

void GetSensorDataFromConsole(float* Temperature, float* SOC, float* ChargeRate)
{
  int readingIndex = 0;
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    scanf("%f,%f,%f",&Temperature[readingIndex],&SOC[readingIndex],&ChargeRate[readingIndex]);
  }
  
  for(readingIndex = 0; readingIndex < NO_OF_READINGS; readingIndex++)
  {
    printf("%f,%f,%f\n",Temperature[readingIndex],SOC[readingIndex],ChargeRate[readingIndex]);

}

void BMSReceiver()
{
  float Temperature[NO_OF_READINGS],SOC[NO_OF_READINGS],ChargeRate[NO_OF_READINGS];
  GetSensorDataFromConsole(&Temperature[0],&SOC[0],&ChargeRate[0]);
}
