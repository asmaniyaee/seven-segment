#include <WiFi.h>
#include <time.h>
#include <TM1637Display.h>

#define CLK 18
#define DIO 19
TM1637Display display(CLK, DIO);

void setup() {
  display.setBrightness(5);
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) delay(200);

  
  configTime(12600, 0, "pool.ntp.org");
}

void loop() {
  struct tm t;
  if (getLocalTime(&t)) {
    int value = t.tm_hour * 100 + t.tm_min;
   
    uint8_t colon = (t.tm_sec % 2) ? 0b01000000 : 0;
    display.showNumberDecEx(value, colon, true);
  }
  delay(200);
}