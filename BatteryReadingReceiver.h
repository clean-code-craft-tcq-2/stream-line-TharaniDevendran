#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void GetSensorDataFromConsole(float* Temperature, float* SOC, float* ChargeRate);
float GetParameterMaxReadingValue(float *BMSParameter);
float GetParameterMinReadingValue(float *BMSParameter);
float GetParameterSMAValue(float *BMSParameter);
void PrintReceivedDataOnConsole(float *BMSParameter, float MaxValue, float Minvalue, float SMA);
void BMSReceiver(float* Temperature, float* SOC, float* ChargeRate);
