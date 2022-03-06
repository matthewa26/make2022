// Include the library:
#include <LiquidCrystal.h>
#include <String.h>
// Create an LCD object.
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

const int LED_BLUE = 13;
const int LED_GREEN = 12;
const int LED_YELLOW = 11;
const int LED_RED = 10;
const int LED_DELAY = 100;
const int SWITCH_LIGHT = 1;

int red_light_pin= 7;
int green_light_pin = 9;
int blue_light_pin = 8;

int buttonState = 0;
int counter = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(SWITCH_LIGHT, INPUT);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:


    // LCD test code
  
    // Set the cursor on the third column and the first row, counting starts at 0:
    lcd.setCursor(0, 0);
    // Print the string 'Hello World!':
    lcd.print("~The Imagineers~");

  

    buttonState = digitalRead(SWITCH_LIGHT);

    if (counter == 0) {
      // All lights off
      setScreen(1, "   Lights Off   ");
      digitalWrite(LED_RED, LOW); 
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
    } else if (counter == 1) {
      RGB_color(0, 0, 0); // RGB Light OFF
      // Always on
      setScreen(1, "   Lights On!   ");
      digitalWrite(LED_RED, HIGH); 
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_BLUE, HIGH)  ;
    } else if (counter == 2) {
      // cinema lights
      setScreen(1, "     Police     ");
      RGB_color(0, 0, 0); // RGB Light OFF
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(LED_RED, HIGH); 
      delay(LED_DELAY);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_BLUE, HIGH);
      delay(LED_DELAY);
    } else if (counter == 3) {
      setScreen(1, " Weather Hazard ");
      RGB_color(0, 0, 0); // RGB Light OFF
      // Reverse cinema lights
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      digitalWrite(LED_YELLOW, HIGH); 
      delay(LED_DELAY);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, HIGH);
      delay(LED_DELAY);
    } else if (counter == 4) {
      setScreen(1, "      Calm      ");
      RGB_color(0, 0, 0); // RGB Light OFF
      // Pyramid lights
      digitalWrite(LED_RED, HIGH);
      delay(LED_DELAY * 2);
      digitalWrite(LED_YELLOW, HIGH);
      delay(LED_DELAY* 2);
      digitalWrite(LED_GREEN, HIGH);
      delay(LED_DELAY * 2);
      digitalWrite(LED_BLUE, HIGH);
      delay(LED_DELAY * 6);
      digitalWrite(LED_RED, LOW);
      delay(LED_DELAY * 2);
      digitalWrite(LED_YELLOW, LOW);
      delay(LED_DELAY * 2);
      digitalWrite(LED_GREEN, LOW);
      delay(LED_DELAY * 2);
      digitalWrite(LED_BLUE, LOW);
      delay(LED_DELAY * 6);
    }
    RGB_color(0, 130, 130); // RGB Light ON purple

    if (buttonState == HIGH) {
      setScreen(1, "Switching Lights");
      flashDelay(0, 255, 0, 600);
      counter++;
      if (counter > 4) {
        counter = 0;
      }
      delay(500);
    } else {
      RGB_color(0, 0, 0); // RGB Light OFF
    }
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  //analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void flashDelay(int red_light_value, int green_light_value, int blue_light_value, int delayValue)
{
  int delayTime = 0;
  while (delayTime < delayValue) {
    RGB_color(red_light_value, green_light_value, blue_light_value);
    delay(30);
    RGB_color(0, 0, 0);
    delay(30);
    delayTime += 60;
  }
}

void setScreen(int line, String text) {
    lcd.setCursor(0, line);
    // Print the string 'LCD tutorial':
    lcd.print(text);
}
