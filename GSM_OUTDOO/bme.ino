#include "constant.h"

#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
// I2C for BME280 sensor
//TwoWire I2CBME = TwoWire(1);
Adafruit_BME280 bme;

float temp, humidity;
void bme_setup()
{
  //I2CBME.begin(I2C_SDA_2, I2C_SCL_2, 400000);
  if (!bme.begin(0x76)) {
    SerialMon.println("_Could not find a valid BME280 sensor, check wiring!");
   // while (1);
  }
}

void bme_loop()
{
  Serial.print("Temperature = ");
  temp = bme.readTemperature();
  Serial.print(temp);
  Serial.println(" *C");

  Serial.print("Humidity = ");
  humidity = bme.readHumidity();
  Serial.print(humidity);
  Serial.println(" %");
}
