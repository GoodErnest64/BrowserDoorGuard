import serial
import keyboard
import pyautogui

s = serial.Serial("<Your Serial Port>") #Put Your Serial Port e.g. COM1

while 1:
    if keyboard.is_pressed("q"):
        break
    if s.read(13): #Put Your MSG Byte Size
        pyautogui.moveTo((1250, 16)) # Put Your Minimize Button Location
        pyautogui.click()

print("Program Closing...")
