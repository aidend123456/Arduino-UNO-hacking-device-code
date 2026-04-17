void setup() {
  Serial.begin(9600);
}

void loop() {

  // Move 4 pixels Right
  uint8_t moveRight[4] = {0, 4, 0, 0};
  Serial.write(moveRight, 4);
  delay(100);

  // Move 4 pixels Left
  uint8_t moveLeft[4] = {0, (uint8_t)-4, 0, 0};
  Serial.write(moveLeft, 4);

  delay(30000); // Wait 30 seconds
}
