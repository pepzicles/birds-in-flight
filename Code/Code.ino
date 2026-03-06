const int enPin = 8;
const int buttonPin = A0; // Using A0 as the safety switch pin, labelled 'abort'pin and GND

// X Axis Pins
const int stepXPin = 2;
const int dirXPin = 5;

// Y Axis Pins
const int stepYPin = 3;
const int dirYPin = 6;

// Z Axis Pins
const int stepZPin = 4;
const int dirZPin = 7;

// Speed Control
int pulseWidthMicros = 100;     
int stepDelayMicros = 2000;     

void setup() {
  Serial.begin(9600);

  // Setup Button with internal pull-up
  // Button should connect Pin A0 to GND
  pinMode(buttonPin, INPUT_PULLUP);

  // Enable motor drivers
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, HIGH); // Start DISABLED for safety

  // Set all step and direction pins as outputs
  pinMode(stepXPin, OUTPUT);
  pinMode(dirXPin, OUTPUT);
  pinMode(stepYPin, OUTPUT);
  pinMode(dirYPin, OUTPUT);
  pinMode(stepZPin, OUTPUT);
  pinMode(dirZPin, OUTPUT);

  // Set directions
  digitalWrite(dirXPin, HIGH);
  digitalWrite(dirYPin, HIGH);
  digitalWrite(dirZPin, HIGH);

  Serial.println(F("System Ready. Toggle button to begin."));
}

void loop() {
  // Check if the button is pressed (connected to GND)
  if (digitalRead(buttonPin) == LOW) {
    // 1. Enable the drivers (LOW = ON for CNC Shields)
    digitalWrite(enPin, LOW); 

    // 2. Step the motors
    digitalWrite(stepXPin, HIGH);
    digitalWrite(stepYPin, HIGH);
    digitalWrite(stepZPin, HIGH);
    delayMicroseconds(pulseWidthMicros);

    digitalWrite(stepXPin, LOW);
    digitalWrite(stepYPin, LOW);
    digitalWrite(stepZPin, LOW);
    delayMicroseconds(stepDelayMicros);
  } 
  else {
    // If button is NOT connected or OFF:
    // Disable the drivers to stop movement and prevent motor heating
    digitalWrite(enPin, HIGH); 
  }
}
