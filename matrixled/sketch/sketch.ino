#include <Arduino_LED_Matrix.h>

uint8_t logo[104] = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,1,1,1,0,0,0,1,1,1,0,0,
    0,1,0,0,0,1,0,1,0,0,0,1,0,
    1,0,0,0,0,0,1,0,0,3,0,0,1,
    1,0,3,3,3,0,1,0,3,3,3,0,1,
    1,0,0,0,0,0,1,0,0,3,0,0,1,
    0,1,0,0,0,1,0,1,0,0,0,1,0,
    0,0,1,1,1,0,0,0,1,1,1,0,0
};
uint8_t led_array[104];

Arduino_LED_Matrix matrix;

void setup() {
  matrix.begin();
  // display the image
  matrix.setGrayscaleBits(2);
  matrix.draw(logo);
  
  delay(1000);
  for(int led_no=0; led_no < sizeof(led_array); led_no++){
     led_array[led_no] = 3;
     matrix.draw(led_array);
     delay(100);
     led_array[led_no] = 0;
     matrix.draw(led_array);
   } 
  matrix.draw(logo);
}

void loop() {

}