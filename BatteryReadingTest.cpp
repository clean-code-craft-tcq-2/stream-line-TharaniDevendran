#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include BatteryReadingSender.h
#include "catch.hpp"

TEST_CASE("Tests to check if data is correctly read from file") {
  float Temperature[NO_OF_READINGS] = {0};
  float SOC[NO_OF_READINGS] = {0};
  float ChargeRate[NO_OF_READINGS] = {0};
  ReadBatterReadingsfromFile(Temperature,StateOfCharge,ChargeRate);
  
  float expectedoutput[3][3] = {{49,66,0.34}, {28,67,0.8},{88,90,0.52}};
  for(int i=0;i<3;i++)
  {
    REQUIRE(Temperature[i] == expectedoutput[i][0]);
    REQUIRE(StateOfCharge[i] == expectedoutput[i][1]);
    REQUIRE(ChargeRate[i] == expectedoutput[i][2]);
  }
}
