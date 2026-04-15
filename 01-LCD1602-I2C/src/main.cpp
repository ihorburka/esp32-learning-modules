#include <Arduino.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int x_row1, x_row2;
String buffer_row1, buffer_row2;

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(10000);

    Wire.begin(21, 22);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print(" 01-LCD1602-I2C ");
    lcd.setCursor(0, 1);
    lcd.print(" Date: 09.04.26 ");
}

void loop() {
    Serial.print("Indentation on the first line: ");
    while (Serial.available() == 0)
        delay(10);
    x_row1 = Serial.readStringUntil('\n').toInt();
    Serial.printf("\n");

    Serial.printf("Write a word of up to %d characters: ", 16 - x_row1);
    while (Serial.available() == 0)
        delay(10);
    buffer_row1 = Serial.readStringUntil('\n');
    buffer_row1.trim();
    Serial.printf("\n");

    Serial.print("Indentation on the second line: ");
    while (Serial.available() == 0)
        delay(10);
    x_row2 = Serial.readStringUntil('\n').toInt();
    Serial.printf("\n");

    Serial.printf("Write a word of up to %d characters: ", 16 - x_row2 );
    while (Serial.available() == 0)
        delay(10);
    buffer_row2 = Serial.readStringUntil('\n');
    buffer_row2.trim();
    Serial.printf("\n");

    lcd.clear();    
    lcd.setCursor(x_row1, 0);
    lcd.print(buffer_row1);
    lcd.setCursor(x_row2, 1);
    lcd.print(buffer_row2);
    
    Serial.println("Successfully");

    delay(1000);
}
