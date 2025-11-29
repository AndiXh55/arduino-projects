const int ENABLE = 5;   // PWM pin for motor speed
const int DIRA   = 3;   // Motor driver direction A
const int DIRB   = 4;   // Motor driver direction B
const int BUTTON = 2;   // Button input

bool motorOn = false;          // current motor state
bool lastButtonState = HIGH;   // previous button reading

void setup() {
  pinMode(BUTTON, INPUT_PULLUP); // use internal pull-up, button to GND
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  bool buttonState = digitalRead(BUTTON);

  // detect press: last HIGH → now LOW
  if (lastButtonState == HIGH && buttonState == LOW) {
    motorOn = !motorOn; // toggle motor state
    delay(50);          // debounce delay
  }
  lastButtonState = buttonState;

  if (motorOn) {
    digitalWrite(DIRA, HIGH);
    digitalWrite(DIRB, LOW);
    analogWrite(ENABLE, 255); // motor ON full speed
  } else {
    analogWrite(ENABLE, 0);   // motor OFF
  }
}
