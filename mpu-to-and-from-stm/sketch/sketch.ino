#include "Arduino_RouterBridge.h"

int data = 0;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  delay(2000);

  boolean start = false;

  // Wait until the python is started
  while(!start){
    Bridge.call("linux_started").result(start);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  data++;
  Bridge.notify("python_func", data);
  delay(1000);
}
