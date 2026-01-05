
#include "Arduino_RouterBridge.h"
#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;

// uint8_t logo[104] = {
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0,
//     0,0,0,0,0,0,0,0,0,0,0,0,0
// };

uint8_t logo[104]={0}; // w has type uint8_t[104] and holds all zeroes (the same like above but in one line!)

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Bridge.provide("frame_packet",handleFrame);
  Monitor.begin();
  delay(2000);

  // Wait until the python is started
  boolean start = false;  
  while(!start){
    Bridge.call("linux_started").result(start);
  }

  Monitor.println("Linux started!");
  
  matrix.begin();
  matrix.setGrayscaleBits(1);
}



void loop() {
  // put your main code here, to run repeatedly:
  matrix.draw(logo);
  delay(25);
}

void handleFrame(msgpack::arr_t<uint8_t> data) {
    // data.size() should be 104
    for (size_t i = 0; i < data.size(); i++) {
        logo[i] = data[i];
        //uint8_t v = data[i];
        //Monitor.print(v);
        //Monitor.print(" ");
    }
    //Monitor.println(" end"); 
}