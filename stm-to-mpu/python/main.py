import time
#from arduino.app_utils import App
from arduino.app_utils import *

print("Hello world!")

def python_function(dane: str):
    print(dane)

Bridge.provide("python_function", python_function)

def loop():
    """This function is called repeatedly by the App framework."""
    # You can replace this with any code you want your App to run repeatedly.
    #time.sleep(10)


# See: https://docs.arduino.cc/software/app-lab/tutorials/getting-started/#app-run
App.run(user_loop=loop)
