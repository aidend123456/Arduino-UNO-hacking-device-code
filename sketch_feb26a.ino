#include <string.h>


void typeKey(uint8_t key, uint8_t modifier = 0x00) {
  uint8_t press[8] = {modifier, 0, key, 0, 0, 0, 0, 0};
  uint8_t release_packet[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  Serial.write(press, 8);
  delay(18); 
  Serial.write(release_packet, 8);
  delay(18); 
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // KILL SWITCH
  delay(5000); 
}

void loop() {
  if (digitalRead(2) == LOW) return; // Kill switch active if Pin 2 connected to GND

  uint8_t release[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  
  
  uint8_t ctrlN[8] = {0x01, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00};
  Serial.write(ctrlN, 8); delay(50); Serial.write(release, 8);
  delay(2000); // Wait 2 seconds for the browser to actually open


  typeKey(0x0F, 0x01); // Ctrl + L (Focus)
  delay(200);
  typeKey(0x2A);       // Backspace (Clear any previous junk)
  delay(200);


  typeKey(0x0B); typeKey(0x17); typeKey(0x17); typeKey(0x13); typeKey(0x16); // https
  typeKey(0x33, 0x02); // :
  typeKey(0x38); typeKey(0x38); // //
  typeKey(0x1A); typeKey(0x1A); typeKey(0x1A); typeKey(0x37); // www.
  typeKey(0x1C); typeKey(0x12); typeKey(0x18); typeKey(0x17); typeKey(0x18); typeKey(0x05); typeKey(0x08); typeKey(0x37); // youtube.
  typeKey(0x06); typeKey(0x12); typeKey(0x10); typeKey(0x38); // com/
  
  typeKey(0x4F); // RIGHT ARROW (Cements the text, stops auto-select)

  typeKey(0x1A); typeKey(0x04); typeKey(0x17); typeKey(0x06); typeKey(0x0B); typeKey(0x38, 0x02); // watch?
  typeKey(0x19); typeKey(0x2E); // v=
  typeKey(0x22); typeKey(0x18, 0x02); typeKey(0x19, 0x02); typeKey(0x14); typeKey(0x0C, 0x02); // 5UVqI
  typeKey(0x0A); typeKey(0x1E); typeKey(0x07, 0x02); typeKey(0x20); typeKey(0x1B); typeKey(0x21); // g1D3x4


  typeKey(0x4F); // Right arrow again
  delay(100);
  typeKey(0x28); // ENTER
  

  // If this is too short, the next loop starts before the page loads!
  delay(6000); 
}
