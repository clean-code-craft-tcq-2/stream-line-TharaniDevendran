#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"

TEST_CASE("Tests to check whether sensor data is read from console") {
  float test_Temperature[NO_OF_READINGS] = {0};
  float test_SOC[NO_OF_READINGS] = {0};
  float test_ChargeRate[NO_OF_READINGS] = {0};
  GetSensorDataFromConsole(&test_Temperature[0],&test_SOC[0],&test_ChargeRate[0]);
  
  float expectedoutput[NO_OF_READINGS][3] = {{49,66,0.34}, {28,67,0.8},{88,90,0.52}};
  for(int i=0;i<NO_OF_READINGS;i++)
  {
    REQUIRE(test_Temperature[i] == expectedoutput[i][0]);
    REQUIRE(test_SOC[i] == expectedoutput[i][1]);
    REQUIRE(test_ChargeRate[i] == expectedoutput[i][2]);
  }
}
