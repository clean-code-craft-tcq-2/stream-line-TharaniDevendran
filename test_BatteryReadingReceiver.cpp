#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"
#include "catch.hpp"

TEST_CASE("Tests to check whether sensor data is read from console") {
  float test_Temperature[NO_OF_READINGS] = {0};
  float test_SOC[NO_OF_READINGS] = {0};
  float test_ChargeRate[NO_OF_READINGS] = {0};
  float Current_MaxValue, Current_MinValue, Current_SMAValue, expectedMaxValue, expectedMinValue, expectedSMAValue;
  
  BMSReceiver(&test_Temperature[0],&test_SOC[0],&test_ChargeRate[0]);
  float expectedoutput[2][3] = {{49,66,0.34}, {28,67,0.8}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(test_Temperature[i] == expectedoutput[i][0]);
    REQUIRE(test_SOC[i] == expectedoutput[i][1]);
    REQUIRE(test_ChargeRate[i] == expectedoutput[i][2]);
  }
  
  // Verify Max, Min and SMA values are correct for parameter Temperature
  expectedMaxValue = 92;
  expectedMinValue = -15;
  expectedSMAValue = 57.8;
  Current_MaxValue = GetParameterMaxReadingValue(&test_Temperature[0]);
  Current_MinValue = GetParameterMinReadingValue(&test_Temperature[0]);
  Current_SMAValue = GetParameterSMAValue(&test_Temperature[0]);
  REQUIRE(Current_MaxValue == expectedMaxValue);
  REQUIRE(Current_MinValue == expectedMinValue);
  REQUIRE(Current_SMAValue == expectedSMAValue);
  
  // Verify Max, Min and SMA values are correct for parameter SOC
  expectedMaxValue = 99;
  expectedMinValue = -4;
  expectedSMAValue = 50;
  Current_MaxValue = GetParameterMaxReadingValue(&test_SOC[0]);
  Current_MinValue = GetParameterMinReadingValue(&test_SOC[0]);
  Current_SMAValue = GetParameterSMAValue(&test_SOC[0]);
  REQUIRE(Current_MaxValue == expectedMaxValue);
  REQUIRE(Current_MinValue == expectedMinValue);
  REQUIRE(Current_SMAValue == expectedSMAValue);
  
  // Verify Max, Min and SMA values are correct for parameter ChargeRate
  expectedMaxValue = 1.0;
  expectedMinValue = -0.50;
  expectedSMAValue = 0.234;
  Current_MaxValue = GetParameterMaxReadingValue(&test_ChargeRate[0]);
  Current_MinValue = GetParameterMinReadingValue(&test_ChargeRate[0]);
  Current_SMAValue = GetParameterSMAValue(&test_ChargeRate[0]);
  REQUIRE(Current_MaxValue == expectedMaxValue);
  REQUIRE(Current_MinValue == expectedMinValue);
  
}
