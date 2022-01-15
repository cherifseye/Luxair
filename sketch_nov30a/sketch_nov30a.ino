#include <LiquidCrystal.h>
#include <DHT.h>


#define DHTPIN A1
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int redPin = 11;
int YellowPin = 12;
int greenPin = 13;
int switchON = 8;
int switchOFFtone = 9;
int piezzoPin = 10;
//const int AOUT = A0;
//const int DOUT = 1;


float humidity;
float temperature;
//float COvalue;
//float limitCo;

void setup() {
    dht.begin();
    lcd.begin(16, 2); 
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(YellowPin, OUTPUT);
    pinMode(switchON, INPUT);
    pinMode(switchOFFtone, OUTPUT);
    //pinMode(DOUT, INPUT);
    
}

void loop() {
    
    humidity = dht.readHumidity();
    temperature = dht.readTemperature();
    lcd.print("Temp ");
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(0, 1);
    //COvalue = analogRead(AOUT);
    //limitCo = digitalRead(DOUT);
    lcd.print("Humidity ");
    lcd.print(humidity);
    lcd.print(" %  ");
    int switch1 = digitalRead(switchON);
    int switch2 = digitalRead(switchOFFtone);
    if (temperature < 22){
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 1);
        digitalWrite(YellowPin, 0);
    }
    else if (temperature > 22 && temperature < 29){
        digitalWrite(redPin, 0);
        digitalWrite(greenPin, 0);
        digitalWrite(YellowPin, 1);
    }
    else if (temperature >= 29){
        digitalWrite(redPin, 1);
        digitalWrite(greenPin, 0);
        digitalWrite(YellowPin, 0);
        tone(piezzoPin, 1000, 500);
    }

    if (switchOFFtone == HIGH){
        noTone(piezzoPin);
    }

    if (humidity > 10000){

        digitalWrite(redPin, 1);
        tone(piezzoPin, 1000, 500);
        lcd.clear();
        lcd.print("Warning");
        lcd.setCursor(0, 1);
        lcd.print("Humidity is too high");
        delay(1000);
;
    }
    }
