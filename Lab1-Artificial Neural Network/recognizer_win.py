from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
import os
import sys
import string
from tkinter import filedialog
import tkinter as tk

t = tk.Tk()
filename = filedialog.askopenfilename()
t.withdraw()

pos1 = filename.rfind('faces')
pos2 = filename.rfind('.')

f = open(filename, 'rb')

sht = filename[pos2 + 1:]

filename = "../" + filename[pos1 : pos2 - 1] + "4." + filename[pos2 + 1:]

if (sht != 'pgm'):
    print("The file chosen is not a \'pgm\' image!")
    sys.exit(1)

im = Image.open(f)
im.show()
f.close()

print("Hello, which task should I do?\n")
temp = input("Enter 0 for Face Recognition, 1 for Sunglasses Recognition: ")
in1 = int(temp)

if (in1 == 0):
    file_path = os.path.abspath('./Face Recognition/executable')
else:
    file_path = os.path.abspath('./Sunglasses Recognition/executable')
    
op = "test.exe " + filename
os.chdir(file_path)

out = os.popen(op)
print(out.read())

print("Finished testing!\n")