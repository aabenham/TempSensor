#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int tempSensorPin = 0;    // Analog pin for the temperature sensor
const int redLedPin = 3;        // Digital pin for the red LED
const int buzzerPin = 5;        // Digital pin for the buzzer

LiquidCrystal_I2C lcd(0x27, 16, 2); 

float temperatureC;
float temperatureF; 

void setup() 
{
pinMode(redLedPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);

lcd.init();
lcd.backlight();
lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(temperatureF);
lcd.print(" F"); 
}

void loop() {

// Read temperature from analog sensor
int reading = analogRead(tempSensorPin);
float voltage = reading * 5.0;
voltage /= 1024.0;

// Convert analog value to temperature in Celsius
temperatureC = (voltage - 0.5) * 100 ;
temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

lcd.setCursor(0, 1);
lcd.print("Temp: ");
lcd.print(temperatureF);
lcd.print(" F"); 



if (temperatureF > 75.0 || temperatureF < 60.0) {

digitalWrite(redLedPin, HIGH);
tone(buzzerPin, 1000); 
delay(500);
digitalWrite(redLedPin, LOW);
noTone(buzzerPin);
delay(500);
} 
else {
    noTone(buzzerPin);
}

// Delay before reading the temperature again
delay(500); 
}
