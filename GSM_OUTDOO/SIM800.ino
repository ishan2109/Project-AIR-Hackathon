#include "constant.h"
#include "SIM800.h"

#include <Wire.h>
// Set serial for debug console (to Serial Monitor, default speed 115200)
#define SerialMon Serial
// Set serial for AT commands (to SIM800 module)
#define SerialAT Serial1


// I2C for SIM800 (to keep it running when powered from battery)
TwoWire I2CPower = TwoWire(0);
// Define the serial console for debug prints, if needed
//#define DUMP_AT_COMMANDS

//#include <Wire.h>
#include <TinyGsmClient.h>

#ifdef DUMP_AT_COMMANDS
#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, SerialMon);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif






// TinyGSM Client for Internet connection
TinyGsmClient client(modem);



bool setPowerBoostKeepOn(int en) {
  I2CPower.beginTransmission(IP5306_ADDR);
  I2CPower.write(IP5306_REG_SYS_CTL0);
  if (en) {
    I2CPower.write(0x37); // Set bit1: 1 enable 0 disable boost keep on
  } else {
    I2CPower.write(0x35); // 0x37 is default reg value
  }
  return I2CPower.endTransmission() == 0;
}

void gsm_setup() {
  // Set serial monitor debugging window baud rate to 115200
  // SerialMon.begin(115200);

  // Start I2C communication
  I2CPower.begin(I2C_SDA, I2C_SCL, 400000);

  // Keep power when running from battery
  bool isOk = setPowerBoostKeepOn(1);
  SerialMon.println(String("IP5306 KeepOn ") + (isOk ? "OK" : "FAIL"));

  // Set modem reset, enable, power pins
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  // Set GSM module baud rate and UART pins
  SerialAT.begin(9600, SERIAL_8N1, MODEM_RX, MODEM_TX);
  delay(3000);

  // Restart SIM800 module, it takes quite some time
  // To skip it, call init() instead of restart()
  SerialMon.println("Initializing modem...");
  modem.restart();
  // use modem.init() if you don't need the complete restart

  // Unlock your SIM card with a PIN if needed
  if (strlen(simPIN) && modem.getSimStatus() != 3 ) {
    modem.simUnlock(simPIN);
  }
  SerialMon.print("Connecting to APN: ");
  SerialMon.print(APN);
  if (!modem.gprsConnect(APN, gprsUser, gprsPass))
  {
    SerialMon.println(" fail");
  }
  else {
    SerialMon.println(" OK");
  }



  // Configure the wake up source as timer wake up
  // esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
}

void gsm_loop() {
  SerialMon.print("Connecting to APN: ");
  SerialMon.print(APN);
  if (!modem.isGprsConnected())
  {
    SerialMon.println(" Not connected");
    SerialMon.println(" Try Connecting");
    SerialMon.print("Connecting to APN: ");
    SerialMon.print(APN);
    int r=0;
    if (!modem.gprsConnect(APN, gprsUser, gprsPass)) //&& (r<30))
    {
      SerialMon.println(" fail");
     //debug_info(".");
      r++;
    }
    else {
      SerialMon.println(" OK");
    }
  }
  else {
    SerialMon.println(" Connected");

  }
  SerialMon.print(modem.getSimStatus());

    if (!modem.gprsConnect(APN, gprsUser, gprsPass)) {
      SerialMon.println(" fail");
    }
    else {
      SerialMon.println(" OK");
  
      SerialMon.print("Connecting to ");
      SerialMon.print(SERVER);
  
  
    }
  // Put ESP32 into deep sleep mode (with timer wake up)
  // esp_deep_sleep_start();
}
