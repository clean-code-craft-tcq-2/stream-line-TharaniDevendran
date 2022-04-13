#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"
#include "catch.hpp"

TEST_CASE("Tests to check whether sensor data is read from console") {
  float test_Temperature[NO_OF_READINGS] = {0};
  float test_SOC[NO_OF_READINGS] = {0};
  float test_ChargeRate[NO_OF_READINGS] = {0};
  ReadBatterReadingsfromFile(&test_Temperature[0],&test_SOC[0],&test_ChargeRate[0]);
  
  float expectedoutput[2][3] = {{49,66,0.34}, {28,67,0.8}};
  for(int i=0;i<2;i++)
  {
    REQUIRE(test_Temperature[i] == expectedoutput[i][0]);
    REQUIRE(test_SOC[i] == expectedoutput[i][1]);
    REQUIRE(test_ChargeRate[i] == expectedoutput[i][2]);
  }
}
