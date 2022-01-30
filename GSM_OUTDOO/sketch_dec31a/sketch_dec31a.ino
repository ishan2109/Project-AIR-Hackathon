#define VERSION "V0.00.01"

// Do not remove the include below
#include "AirPollution.h"


// buffer to store above readings
struct sensors_data data_15_sec[PRIMARY_BUF_COUNT];
struct sensors_data data_10_min[SEC_BUF_COUNT];

short int idx_data_15_sec = 0;
short int idx_data_10_min = 0;
short int hist_start_idx = 0;

bool hist_idx_saved = false;

static bool wifi_connected = false;

static bool no_network = false;

static uint32_t last_thngspk_pub = 0;
static uint32_t last_retry_wifi = 0;

static uint32_t retry_wifi_interval = RETRY_WIFI_INTERVAL;

#ifdef DEBUG
static uint32_t loop_start_milli = 0;
static uint32_t loop_end_milli = 0;
#endif

int count_hw = 0;
int pub_status_thngspk = 0;
//int cal_status_avg = 0;
int flag = 0;
void print_dm_stats();
void read_data_from_hw();
int calc_10_min_avg();
int retry_wifi();

bool is_thngspk_pub_due(unsigned long milli);

void setup()
{
  Serial.begin(9600);
  Serial.print("***** Setup (from Eclipse ");
  Serial.print(VERSION);
  Serial.println(") *****");

#ifdef DEBUG
  loop_start_milli = millis();
  debug_info(get_date_timestamp_str(get_timestamp(loop_start_milli), Timeoffset)
             + ": Setup start...\n");
#endif

}
