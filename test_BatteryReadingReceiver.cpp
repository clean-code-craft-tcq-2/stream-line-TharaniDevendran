#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"
#include "catch.hpp"

TEST_CASE("Tests to check whether sensor data is read from console") {
  float test_Temperature[NO_OF_READINGS] = {0};
  float expectedMaxValue_temp = 92;
  float expectedMinValue_temp = -15;
  float expectedSMAValue_temp = 57.8;
  
  float test_SOC[NO_OF_READINGS] = {0};
  float expectedMaxValue_soc = 99;
  float expectedMinValue_soc = -4;
  float expectedSMAValue_soc = 50;
  
  float test_ChargeRate[NO_OF_READINGS] = {0};
  float expectedMaxValue_chargeRate = 1.0;
  float expectedMinValue_chargeRate = -0.05;
  float expectedSMAValue_chargeRate = 0.234;
  
  GetSensorDataFromConsole(&test_Temperature[0],&test_SOC[0],&test_ChargeRate[0]);
  
  float expectedoutput[2][3] = {{49,66,0.34}, {28,67,0.8}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(test_Temperature[i] == expectedoutput[i][0]);
    REQUIRE(test_SOC[i] == expectedoutput[i][1]);
    REQUIRE(test_ChargeRate[i] == expectedoutput[i][2]);
  }
  
  // Verify Max, Min and SMA values are correct for parameter Temperature
  REQUIRE(GetParameterMaxReadingValue(&test_Temperature[0]),expectedMaxValue_temp);
  REQUIRE(GetParameterMinReadingValue(&test_Temperature[0]),expectedMinValue_temp);
  REQUIRE(GetParameterSMAValue(&test_Temperature[0]),expectedSMAValue_temp);
  
  // Verify Max, Min and SMA values are correct for parameter SOC
  REQUIRE(GetParameterMaxReadingValue(&test_SOC[0]),expectedMaxValue_soc);
  REQUIRE(GetParameterMinReadingValue(&test_SOC[0]),expectedMinValue_soc);
  REQUIRE(GetParameterSMAValue(&test_SOC[0]),expectedSMAValue_soc);
  
  // Verify Max, Min and SMA values are correct for parameter ChargeRate
  REQUIRE(GetParameterMaxReadingValue(&test_ChargeRate[0]),expectedMaxValue_chargeRate);
  REQUIRE(GetParameterMinReadingValue(&test_ChargeRate[0]),expectedMinValue_chargeRate);
  REQUIRE(GetParameterSMAValue(&test_ChargeRate[0]),expectedSMAValue_chargeRate);
  
}
