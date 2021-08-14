/*
 * Author: Prashant Band
 * Description: Example code for button press event on ESP8266
 * PIN Configurations: D5 and D6 Pins
 */

// Constant button configuration on PIN
const int  button1 = D5;
const int button2 = D6;

// Variables will change:
int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastbuttonState1 = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(button1, INPUT);
  // initialize the LED as an output:
  pinMode(button2, INPUT);
  // initialize serial communication:
  Serial.begin(115200);
}


void loop() {
  // read the button:
  buttonState1 = digitalRead(button1);

  // compare the button state to its previous state
  if (buttonState1 != lastbuttonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter1++;
      Serial.print("Button1 Pressed");
      Serial.println(buttonPushCounter1);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("Button1 Released");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastbuttonState1 = buttonState1;


  // LED state change for every four button pushes
  if (buttonPushCounter1 % 4 == 0) {
    digitalWrite(Button2, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(Button2, LOW);
    Serial.println("OFF");
  }
}