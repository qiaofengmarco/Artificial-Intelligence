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
	plt.scatter(x, y2, s = 10)
	plt.axis([0, 10000, 0, 2])
	plt.xlabel('Numbers of Weight Update')
	plt.ylabel('Training Error')
	plt.figure(u'训练集正确率')
	plt.axis([0, 10000, 0.2, 1])	
	plt.scatter(x, y1, s = 10)
	plt.xlabel('Numbers of Weight Update')
	plt.ylabel('Training Accuracy')	
	plt.show()
finally:
	if f:
		f.close()
