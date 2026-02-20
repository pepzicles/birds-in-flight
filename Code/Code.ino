const int enPin = 8;

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
int pulseWidthMicros = 100;     // Time to keep step pin HIGH (microseconds)
int stepDelayMicros = 2000;     // Delay between steps — smaller = faster

void setup() {
  Serial.begin(9600);

  // Enable motor drivers
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW); // LOW to enable

  // Set all step and direction pins as outputs
  pinMode(stepXPin, OUTPUT);
  pinMode(dirXPin, OUTPUT);

  pinMode(stepYPin, OUTPUT);
  pinMode(dirYPin, OUTPUT);

  pinMode(stepZPin, OUTPUT);
  pinMode(dirZPin, OUTPUT);

  // Set direction to clockwise (can be HIGH or LOW depending on driver wiring)
  digitalWrite(dirXPin, HIGH);
  digitalWrite(dirYPin, HIGH);
  digitalWrite(dirZPin, HIGH);

  Serial.println(F("CNC Shield Continuous Rotation Initialized"));
}

void loop() {
  // Step all three motors once
  digitalWrite(stepXPin, HIGH);
  digitalWrite(stepYPin, HIGH);
  digitalWrite(stepZPin, HIGH);
  delayMicroseconds(pulseWidthMicros);

  digitalWrite(stepXPin, LOW);
  digitalWrite(stepYPin, LOW);
  digitalWrite(stepZPin, LOW);
  delayMicroseconds(stepDelayMicros); // Adjust this to change speed
}
