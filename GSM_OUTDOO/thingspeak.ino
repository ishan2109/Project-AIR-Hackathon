#include <ThingSpeak.h>
void thingspeak_setup()
{
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void thingspeak_loop()
{
  Serial.print("I am here");
  ThingSpeak.setField(1, SDS_25);
  ThingSpeak.setField(2, SDS_10);
  ThingSpeak.setField(3, temp);
  ThingSpeak.setField(4, humidity);
  ThingSpeak.setField(5, results);
  
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, API);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(1000);
}
