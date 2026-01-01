import time
from arduino.app_utils import *

#used only for sync purposes
def linux_started():
  return True

print("This print Python-It comes from STM by Bridge!")
def python_func (data: int):
  print(data)

Bridge.provide("linux_started", linux_started)
Bridge.provide("python_func", python_func)

def loop():
    """This function is called repeatedly by the App framework."""
    # You can replace this with any code you want your App to run repeatedly.
    time.sleep(1)


# See: https://docs.arduino.cc/software/app-lab/tutorials/getting-started/#app-run
App.run(user_loop=loop)
