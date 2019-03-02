#include <LiquidCrystal.h>
#include "DHT.h";

#define DHTPIN 2
#define DHTTYPE DHT22

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURA: ");
  lcd.setCursor(6, 1);
  lcd.print(char(223));
  lcd.print("C");
}

void loop() {
  delay(2000);
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    lcd.setCursor(0, 1);
    lcd.print("ERRO AO LER TEMP");
    return;
  }

  lcd.setCursor(0, 1);
  lcd.print(temp);

}
