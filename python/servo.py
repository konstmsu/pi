import RPi.GPIO as GPIO
import time

servoPIN = 17
GPIO.setmode(GPIO.BCM)
GPIO.setup(servoPIN, GPIO.OUT)

p = GPIO.PWM(servoPIN, 50)  # GPIO 17 for PWM with 50Hz
middle = 7.5
p.start(middle)  # Initialization
seq = range(-5, 6, 1)
try:
    while True:
        for s in seq:
            print("Going to", s)
            p.ChangeDutyCycle(s + middle)
            time.sleep(1)
except KeyboardInterrupt:
    p.stop()
    GPIO.cleanup()
