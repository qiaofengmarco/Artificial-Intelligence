import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

try:
	f = open('training_record.txt', 'r')
	a = []
	b = []
	count = 0
	str = ""
	for line in f.readlines():
		count = count + 1
		str = line.strip()
		a.append(float(str))
		b.append(count)
	y = np.array(a)
	x = np.array(b)
	plt.figure(u'训练误差')
	plt.plot(x, y)
	plt.axis([0, 250000, 0, 0.4])
	plt.xlabel('Numbers of Weight Update')
	plt.ylabel('Training Error')
	plt.show()
finally:
	if f:
		f.close()
