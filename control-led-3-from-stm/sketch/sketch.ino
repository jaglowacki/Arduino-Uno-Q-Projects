#include <Arduino_RouterBridge.h>

int incomingByte = 0;

void setup() {
  // Configure the pins as outputs
  pinMode(LED3_R, OUTPUT);
  pinMode(LED3_G, OUTPUT);
  pinMode(LED3_B, OUTPUT);
  // As they are active low, turn them OFF initially
  digitalWrite(LED3_R, HIGH);
  digitalWrite(LED3_G, HIGH);
  digitalWrite(LED3_B, HIGH);

  //Monitor.begin();
}

void loop() {
  digitalWrite(LED3_R, LOW);  // Turn ON red segment
  digitalWrite(LED3_G, HIGH);
  digitalWrite(LED3_B, HIGH);
  Monitor.println("Świeci dioda CZERWONA");
  delay(1000);
    
  //while (Monitor.available() == 0) {};
  //incomingByte = Monitor.read();
  //Monitor.print("I received: ");
  //Monitor.println(incomingByte, DEC);
 
  digitalWrite(LED3_R, HIGH);
  digitalWrite(LED3_G, LOW);  // Turn ON green segment
  digitalWrite(LED3_B, HIGH);
  Monitor.println("Świeci dioda ZIELONA");
  delay(1000);
  digitalWrite(LED3_R, HIGH);
  digitalWrite(LED3_G, HIGH);
  digitalWrite(LED3_B, LOW);  // Turn ON blue segment
  Monitor.println("Świeci dioda NIEBIESKA");
  delay(1000);
}
