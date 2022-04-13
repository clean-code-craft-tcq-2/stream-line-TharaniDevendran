#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "BatteryReadingReceiver.h"
#include "BatteryReadingSender.h"

TEST_CASE("Tests to check whether sensor data is read from console") {
  float Temperature[NO_OF_READINGS], SOC[NO_OF_READINGS], ChargeRate[NO_OF_READINGS];
  float test_Temperature[NO_OF_READINGS], test_SOC[NO_OF_READINGS], test_ChargeRate[NO_OF_READINGS];
  float temp,soc,chrRate;
  int index;
  
  //Call receiver to read sensor data
  GetSensorDataFromConsole(&Temperature[0],&SOC[0],&ChargeRate[0]);
  
  FILE *test_SensorData_fp = fopen("./Battery_Reading.txt","r");
  
  for(index = 0; fscanf(test_SensorData_fp, "%f %f %f\n", &temp, &soc, &chrRate)!=EOF; index++)
  {
      test_Temperature[index] = temp;
      test_SOC[index] = soc;
      test_ChargeRate[index] = chrRate;
  }
  
  //Verify that readings are read from input file
  for(index = 0; index < NO_OF_READINGS; index++)
  {
    REQUIRE(Temperature[index] == test_Temperature[index]);
    REQUIRE(SOC[index] == test_SOC[index]);
    REQUIRE(ChargeRate[index] == test_ChargeRate[index]);
  }
  
  fclose(test_SensorData_fp);
}
