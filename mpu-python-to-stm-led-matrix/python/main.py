import time

from arduino.app_utils import *

#used only for sync purposes
def linux_started():
  return True

Bridge.provide("linux_started", linux_started)

your_flattened_8x13_list_I = [0,0,0,1,1,1,1,1,1,1,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,0,0,0,1,0,0,0,0,0,0,
                              0,0,0,1,1,1,1,1,1,1,0,0,0]

your_flattened_8x13_list_II = [0,0,0,1,1,1,1,1,1,1,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,0,1,0,0,0,1,0,0,0,0,
                               0,0,0,1,1,1,1,1,1,1,0,0,0]

counter=0

def loop():
    """This function is called repeatedly by the App framework."""
    # You can replace this with any code you want your App to run repeatedly.
    global counter
    if counter==0:
      your_flattened_8x13_list=your_flattened_8x13_list_I
      counter+=1
    else:
      your_flattened_8x13_list=your_flattened_8x13_list_II
      counter=0
    frame = bytes(your_flattened_8x13_list)  # 104 values
    Bridge.call("frame_packet", frame)
    time.sleep(1)


# See: https://docs.arduino.cc/software/app-lab/tutorials/getting-started/#app-run
App.run(user_loop=loop)
