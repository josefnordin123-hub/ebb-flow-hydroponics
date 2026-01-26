#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --------------------
// Pin configuration
// --------------------
#define RELAY_PIN  26        // GPIO connected to relay IN pin
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// --------------------
// Timing (milliseconds)
// --------------------
const unsigned long FLOOD_DURATION  = 5UL * 60UL * 1000UL;   // 5 minutes
const unsigned long DRAIN_INTERVAL  = 30UL * 60UL * 1000UL;  // 30 minutes

// --------------------
// Display
// --------------------
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --------------------
// State
// --------------------
bool pumpOn = false;
unsigned long lastSwitchTime = 0;

// --------------------
// Setup
// --------------------
void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Pump OFF by default

  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true); // Stop if display fails
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  displayStatus("System booting...");
  delay(2000);

  lastSwitchTime = millis();
}

// --------------------
// Loop
// --------------------
void loop() {
  unsigned long currentTime = millis();

  if (pumpOn && (currentTime - lastSwitchTime >= FLOOD_DURATION)) {
    pumpOff();
  }

  if (!pumpOn && (currentTime - lastSwitchTime >= DRAIN_INTERVAL)) {
    pumpOnFunc();
  }

  updateDisplay(currentTime);
  delay(500);
}

// --------------------
// Functions
// --------------------
void pumpOnFunc() {
  digitalWrite(RELAY_PIN, HIGH);
  pumpOn = true;
  lastSwitchTime = millis();
}

void pumpOff() {
  digitalWrite(RELAY_PIN, LOW);
  pumpOn = false;
  lastSwitchTime = millis();
}

void displayStatus(const char* message) {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(message);
  display.display();
}

void updateDisplay(unsigned long now) {
  display.clearDisplay();
  display.setCursor(0, 0);

  if (pumpOn) {
    display.println("Pump: ON");
    unsigned long remaining = (FLOOD_DURATION - (now - lastSwitchTime)) / 1000;
    display.print("Flood ends in: ");
    display.print(remaining);
    display.println(" s");
  } else {
    display.println("Pump: OFF");
    unsigned long remaining = (DRAIN_INTERVAL - (now - lastSwitchTime)) / 1000;
    display.print("Next flood in: ");
    display.print(remaining);
    display.println(" s");
  }

  display.display();
}
