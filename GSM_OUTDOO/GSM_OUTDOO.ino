#define VERSION "v1.0.02"
#include "GSM_OUTDOOR.h"

#define SerialMon Serial
static uint32_t currentTicks = 0;
static uint32_t startTicks = 0;

#ifdef DEBUG
static uint32_t loop_start_milli = 0;
static uint32_t loop_end_milli = 0;
#endif


void setup() {
  // put your setup code here, to run once:
  SerialMon.begin(9600);  // Initialize serial
  rtc_setup();
  gsm_setup();
  sds_setup();
  bme_setup();
  co_setup();
  thingspeak_setup();




}

void loop() {
  // put your main code here, to run repeatedly:
  currentTicks = millis();
  currentTicks -= startTicks;
  if (currentTicks >= TIME_INTERVAL_30_SEC) {
    rtc_loop();
    sds_loop();
    bme_loop();
    co_loop();
    gsm_loop();
    startTicks = millis();
    thingspeak_loop();

    //currentTicks = startTicks;
  }
}
