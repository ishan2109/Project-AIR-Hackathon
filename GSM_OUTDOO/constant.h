
/*
   uncomment to print debug statements
*/
//#define DEBUG true

// Your GPRS credentials (leave empty, if not needed)
#define APN "cmnet" // APN (example: internet.vodafone.pt) use https://wiki.apnchanger.org
#define gprsUser "" // GPRS User
#define gprsPass "" // GPRS Password

// SIM card PIN (leave empty, if not defined)
#define simPIN "" 

// Server details
// The server variable can be just a domain name or it can have a subdomain. It depends on the service you are using
#define SERVER "api.thingspeak.com" // domain name: example.com, maker.ifttt.com, etc

// Keep this API Key value to be compatible with the PHP code provided in the project page. 
// If you change the API value, the PHP file /post-data.php also needs to have the same key 
#define API "YOUR KEY HERE"
#define myChannelNumber xxxxxx

// TTGO T-Call pins
#define MODEM_RST            5
#define MODEM_PWKEY          4
#define MODEM_POWER_ON       23
#define MODEM_TX             27
#define MODEM_RX             26
#define I2C_SDA              21
#define I2C_SCL              22
// BME280 pins
#define I2C_SDA_2            21
#define I2C_SCL_2            22




#define SDS25_INT 19
#define SDS10_INT 18


#define TIME_INTERVAL_30_SEC 10000
#define Timeoffset 19800

///*
//  Debug Function
//*/
//#if DEBUG
//#define debug_info(fmt, ...) Serial.print(fmt, ##__VA_ARGS__)
//#define debug_err(fmt, ...) Serial.print(fmt, ##__VA_ARGS__)
//#else
//#define debug_info(fmt, ...) ((void)0)
//#define debug_err(fmt, ...) ((void)0)
//#endif
