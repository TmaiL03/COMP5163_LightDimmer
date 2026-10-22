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

  // Read button and resistor inputs.
  int iButton = digitalRead(D5);
  int resistorVal = analogRead(A0);

  digitalWrite(D4, resistorVal);

  // Update program button state when button is initially pressed.
  if(buttonState == LOW && iButton == HIGH) {
    isOn = !isOn;
  }

  if(isOn) {
    // Rotating resistor will affect LED brightness.
    analogWrite(D4, resistorVal);
  }

  // Update buttonState.
  buttonState = iButton;

  // Adding small delay to address noise in current spikes (caused LED to sporadically
  // illuminate when moving the variable resistor while button was in an OFF state.)
  delay(50);
}