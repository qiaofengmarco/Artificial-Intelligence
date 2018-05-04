from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
import os
from tkinter import filedialog
import tkinter as tk

t = tk.Tk()
filename = filedialog.askopenfilename()
t.withdraw()

f = open(filename, 'rb')
im = Image.open(f)
im.show()
f.close()

pos1 = filename.rfind('faces')
pos2 = filename.rfind('.')

filename = "../" + filename[pos1 : pos2 - 1] + "4." + filename[pos2 + 1:]

op = "test.exe " + filename

file_path = os.path.abspath('./executable')

os.chdir(file_path)

out = os.popen(op)
print(out.read())

print("Finished testing!")
print("\n")