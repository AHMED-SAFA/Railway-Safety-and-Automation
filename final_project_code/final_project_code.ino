const int trigPin = 10;
const int echoPin = 12;
const int ledPin = 5;
const int distanceThreshold = 20;  

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Start with LED off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Send a 10us pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin and calculate the duration of the pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the duration of the pulse
  // Speed of sound is 34300 cm/s, so divide by 2 (for round trip) and divide by 29.1 (speed of sound in microseconds)
  int distance = duration / 29.1 / 2;

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is less than the threshold
  if (distance < distanceThreshold) {
    // Blink the LED
    digitalWrite(ledPin, HIGH);
    delay(500);  // LED on for 500 milliseconds
    digitalWrite(ledPin, LOW);
    delay(500);  // LED off for 500 milliseconds
  } else {
    // Ensure LED is off
    digitalWrite(ledPin, LOW);
  }

  // Small delay before the next reading
  delay(100);
}
