
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin Definitions
#define DHTPIN 4        
#define DHTTYPE DHT11   
#define MAGNET_PIN 2    
#define BUZZER_PIN 15   

// Sensor and Display Objects
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables for Time Management
unsigned long previousMillis = 0;
const long interval = 2000;       // 2 seconds for the DHT sensor

unsigned long doorOpenMillis = 0;  // To record the moment the door is opened
bool doorWasOpen = false;         // To track the previous state of the door
const long alarmDelay = 20000;    // Waiting period: 20 seconds (20000 milliseconds)

void setup() {
  pinMode(MAGNET_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW); // Keep the buzzer silent initially
  
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  dht.begin();
  
  lcd.setCursor(3, 0);
  lcd.print("System Ready");
  delay(2000); 
  lcd.clear();
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // --- 1. MAGNETIC SENSOR AND 20-SECOND ALARM LOGIC ---
  if (digitalRead(MAGNET_PIN) == HIGH) {
    // MAGNET IS NEAR (Door is closed)
    digitalWrite(BUZZER_PIN, LOW); // Silence the buzzer immediately
    doorWasOpen = false;           // Reset the door-open status
  } 
  else {
    // MAGNET IS FAR (Door has been opened)
    if (!doorWasOpen) {
      // If the door has JUST been opened, save the current time as a timer
      doorOpenMillis = currentMillis;
      doorWasOpen = true; // Mark the door as open
    }

    // If 20 seconds (alarmDelay) have passed since the door was opened
    if (currentMillis - doorOpenMillis >= alarmDelay) {
      digitalWrite(BUZZER_PIN, HIGH); // Activate the buzzer
    } else {
      digitalWrite(BUZZER_PIN, LOW);  // If 20 seconds have not passed, keep it silent for now
    }
  }

  // --- 2. DHT SENSOR AND LCD DISPLAY UPDATE ---
  // This section updates the temperature on the display every 2 seconds, independently of the door state
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; 

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
      lcd.setCursor(0, 0);
      lcd.print("Sensor Error   ");
      lcd.setCursor(0, 1);
      lcd.print("Check DHT pin  ");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature, 1); 
      lcd.print((char)223);      
      lcd.print("C        ");    

      lcd.setCursor(0, 1);
      lcd.print("Humid: ");
      lcd.print(humidity, 1);    
      lcd.print("%        ");     
    }
  }
}
