import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

try:
	f = open('training_record.txt', 'r')
	correct = []
	error = []
	pos = 0
	b = []
	count = 0
	str = ""
	for line in f.readlines():
		count = count + 1
		str = line.strip()
		pos = str.find(' ')
		correct.append(float(str[:pos]))
		error.append(float(str[pos + 1:]))
		b.append(count)
	y1 = np.array(correct)
	y2 = np.array(error)
	x = np.array(b)
	plt.figure(u'训练误差')
	plt.plot(x, y2)
	plt.axis([0, 140000, 0, 1.5])
	plt.xlabel('Numbers of Weight Update')
	plt.ylabel('Training Error')
	plt.figure(u'训练集正确率')
	plt.axis([0, 140000, 0.1, 0.8])	
	plt.plot(x, y1)
	plt.xlabel('Numbers of Weight Update')
	plt.ylabel('Training Accuracy')	
	plt.show()
finally:
	if f:
		f.close()
