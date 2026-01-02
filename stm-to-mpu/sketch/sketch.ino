#include <Arduino_RouterBridge.h>

char znak;
String dane="";

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Monitor.begin();
  delay(2000);

  // Wait until the python is started
  boolean start = false;  
  while(!start){
    Bridge.call("linux_started").result(start);
  }
}


void loop() {
  if (Monitor.available() > 0) {
    char znak = Monitor.read();
    if (znak == '\n') {
      Monitor.print("Odebrano z Serial i przekazano do MPU: ");
      Monitor.println(dane);
      Bridge.notify("python_function", dane);
      dane = "";   // WYCZYŚĆ bufor
    }
    // Ignoruj \r (Windows)
    else if (znak != '\r') {
      dane += znak;
    }
  }
}
