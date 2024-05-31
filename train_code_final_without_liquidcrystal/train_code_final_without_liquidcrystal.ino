// Define pins for the HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Define pin for the relay module
const int relayPin = 8;

// Variables to store duration and distance
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the trigPin as OUTPUT and echoPin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set the relayPin as OUTPUT
  pinMode(relayPin, OUTPUT);
  
  // Initialize the relay to be off
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.println(" cm");
  
  // If distance is greater than 20 cm, turn on the relay
  if (distance > 20) {
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
  }
  
  delay(500);
}