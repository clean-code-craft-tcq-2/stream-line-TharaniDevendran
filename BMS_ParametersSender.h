#define NO_OF_READINGS 50

void print(float temperature, float SOC, float CR);
void ReadBatterReadingsfromFile(float* Temperature, float* SOC, float* ChargeRate);
void SendBatteryReadingsToConsole(float* Temperature, float* SOC, float* ChargeRate);
void BatterReadingSender();
