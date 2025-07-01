int signal1[] = {13, 12, 11}; // RED, YELLOW, GREEN
int signal2[] = {10, 9, 8};
int signal3[] = {7, 6, 5};
int signal4[] = {4, 3, 2};

int* signals[] = {signal1, signal2, signal3, signal4};

int redDelay = 8000;
int yellowDelay = 2000;

void setup() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pinMode(signals[i][j], OUTPUT);
      digitalWrite(signals[i][j], LOW); // Ensure all start OFF
    }
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    setAllRed(); // All signals RED
    delay(500);  // Small pause before switching to green

    // GREEN ON for current signal
    digitalWrite(signals[i][0], LOW);   // RED OFF
    digitalWrite(signals[i][2], HIGH);  // GREEN ON
    delay(redDelay);                    // Wait while green

    // Switch to YELLOW
    digitalWrite(signals[i][2], LOW);   // GREEN OFF
    digitalWrite(signals[i][1], HIGH);  // YELLOW ON
    delay(yellowDelay);                 // Wait while yellow

    digitalWrite(signals[i][1], LOW);   // YELLOW OFF
    digitalWrite(signals[i][0], HIGH);  // RED ON
  }
}

// Helper function to turn all signals RED
void setAllRed() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(signals[i][0], HIGH); // RED ON
    digitalWrite(signals[i][1], LOW);  // YELLOW OFF
    digitalWrite(signals[i][2], LOW);  // GREEN OFF
  }
}
