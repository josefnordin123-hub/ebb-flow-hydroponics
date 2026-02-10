#include <ESP8266WiFi.h>
#include <time.h>
#include <Wire.h>
#include <U8g2lib.h>
// Note that most of my own comments are in swedish :)
// ================= OLED (SH1106 1.3") =================
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// ================= WIFI =================
const char* SSID = "RoboNet 2.4";
const char* PASS = "robotB3nder";

// ================= TID =================
const long UTC_OFFSET_SECONDS = 3600;   // Sverige vintertid
const int  DST_OFFSET_SECONDS = 0;

// ================= SWITCH =================
// Switch mellan GPIO13 (D7) och GND
const int SWITCH_PIN = 13;   // GPIO13 = D7

// ================= RELÄ / PUMP =================
// Relä på GPIO14 (D5)
const int PUMP_PIN = 14;     // GPIO14 = D5
const bool RELAY_ACTIVE_LOW = true;

// ================= TIME =================
time_t now;
tm timeinfo;

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  pinMode(SWITCH_PIN, INPUT_PULLUP);

  pinMode(PUMP_PIN, OUTPUT);
  // Starta pump OFF
  digitalWrite(PUMP_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);

  // OLED
  Wire.begin(D2, D1); // SDA=D2 (GPIO4), SCL=D1 (GPIO5)
  u8g2.begin();

  // WIFI
  WiFi.begin(SSID, PASS);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(0, 12, "Connecting WiFi...");
  u8g2.sendBuffer();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  configTime(UTC_OFFSET_SECONDS, DST_OFFSET_SECONDS, "pool.ntp.org");

  u8g2.clearBuffer();
  u8g2.drawStr(0, 12, "WiFi connected!");
  u8g2.sendBuffer();
  delay(1000);

  Serial.println("\nBooted.");
  Serial.println("Switch: ON = LOW, OFF = HIGH (INPUT_PULLUP).");
}

// ================= LOOP =================
void loop() {
  updateTime();
  updatePumpFromSwitch();
  drawOLED();
  delay(200);
}

// ================= PUMP (styrs av switch) =================
void updatePumpFromSwitch() {
  bool switchOn = (digitalRead(SWITCH_PIN) == LOW); // LOW = ON

  // Debug
  static bool last = false;
  if (switchOn != last) {
    Serial.print("Switch changed -> ");
    Serial.println(switchOn ? "ON" : "OFF");
    last = switchOn;
  }

  if (switchOn) {
    // Pump ON
    digitalWrite(PUMP_PIN, RELAY_ACTIVE_LOW ? LOW : HIGH);
  } else {
    // Pump OFF
    digitalWrite(PUMP_PIN, RELAY_ACTIVE_LOW ? HIGH : LOW);
  }
}

// ================= TID =================
void updateTime() {
  time(&now);
  localtime_r(&now, &timeinfo);
}

// ================= OLED =================
void drawOLED() {
  char timeStr[9];
  sprintf(timeStr, "%02d:%02d:%02d",
          timeinfo.tm_hour,
          timeinfo.tm_min,
          timeinfo.tm_sec);

  bool switchOn = (digitalRead(SWITCH_PIN) == LOW);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tf);

  u8g2.drawStr(0, 12, "Hydroponic System");

  u8g2.drawStr(0, 28, "Time:");
  u8g2.drawStr(40, 28, timeStr);

  u8g2.drawStr(0, 44, "Switch:");
  u8g2.drawStr(40, 44, switchOn ? "ON" : "OFF");

  u8g2.drawStr(0, 60, "Pump:");
  u8g2.drawStr(40, 60, switchOn ? "ON" : "OFF");

  u8g2.sendBuffer();
}
