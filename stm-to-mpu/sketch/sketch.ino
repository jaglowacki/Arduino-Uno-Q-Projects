#include <Arduino_RouterBridge.h>

char znak;
String dane="";

void setup() {
  // put your setup code here, to run once:
  Monitor.begin();
  //Bridge.begin();
}


void loop() {
  if (Monitor.available() > 0) {
    char znak = Monitor.read();
    if (znak == '\n') {
      Monitor.print("Odebrano: ");
      Monitor.println(dane);
      //Bridge.notify("python_function", dane);
      dane = "";   // WYCZYŚĆ bufor
    }
    // Ignoruj \r (Windows)
    else if (znak != '\r') {
      dane += znak;
    }
  }
  //Bridge.notify("python_function", "123");
  //while (Monitor.available() == 0) {};
  //incomingByte = Monitor.read();
  //Monitor.print("I received: ");
  //Monitor.println(incomingByte, DEC);

}

// #include "Arduino_RouterBridge.h"

// void setup() {
//     pinMode(LED4_G, OUTPUT);
//     pinMode(LED3_R,OUTPUT);
//     digitalWrite(LED4_G, HIGH);
//     digitalWrite(LED3_R, HIGH);

//     Bridge.begin();
//     Bridge.provide("set_led_state", set_led_state);
// }

// void loop() {
// }

// void set_led_state(bool state) {
//     // LOW state means LED is ON
//     digitalWrite(LED4_G, state ? LOW : HIGH);
//     digitalWrite(LED3_R, state ? HIGH : LOW);
// }