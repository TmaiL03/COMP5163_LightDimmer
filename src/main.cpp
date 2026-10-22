#include <Arduino.h>

bool isOn = false;
int buttonState = HIGH;

void setup() {
 // configure the USB serial monitor
 Serial.begin(15200);

 // configure pin D5 as digital input - this is the pushbutton.
 pinMode(D5, INPUT_PULLUP);

 // configure pin D4 as a digital output - this is the LED
 pinMode(D4, OUTPUT);

 // set default PWM range
 analogWriteRange(1023);

}
void loop() {

  // Read button input
  int iButton = digitalRead(D5);
  digitalWrite(D4, iButton);

  // Update program button state when button is initially pressed.
  if(buttonState == LOW && iButton == HIGH) {
    isOn = !isOn;
  }

  if(isOn) {
    int resistorVal = analogRead(A0);

    // Rotating resistor will affect LED brightness.
    analogWrite(D4, resistorVal);
  }

  // Update buttonState.
  buttonState = iButton;

  delay(1);
}