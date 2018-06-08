import numpy as np
import time
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as animation    

legs = []
scats = []

def update_plot(i, data1, data2):
    if (i > 0):
        legs[0].remove()
        scats[0].remove()
        legs.remove(legs[0])
        scats.remove(scats[0])
    else:
        while (len(legs) > 0):
            legs[i].remove()
            scats[i].remove()
            legs.remove(legs[i])
            scats.remove(scats[i])
    scat = plt.scatter(data1[i], data2[i], s = 20, color = 'tomato', label = 'Individuals in the population')
    leg = plt.legend(loc = 'upper left')
    scats.append(scat)
    legs.append(leg)
    
try:
    
    x = np.arange(0, 9, 0.01)

    y = x + 10 * np.sin(5 * x) + 7 * np.cos(4 * x)

    fig = plt.figure('Experiment Result')
    
    plt.axis([0, 9, -16, 26])
    plt.plot(x, y, color = 'orange', label = '$f(x)$ = $x$ + 10$sin(5x)$ + 7$cos(4x)$')
    plt.xlabel('x')
    plt.ylabel('$f(x)$')

    temp11 = []
    temp21 = []
    
    for i in range(1, 52):
        fileName = './' + str(i) + '.txt'
        f = open(fileName, 'r')
        temp1 = []
        temp2 = []
        str1 = ""
        value = 0
        pos = 0
        count = 0
        for line in f.readlines():
            str1 = line.strip()
            value = float(str1)
            temp1.append(value)
            temp2.append(value + 10 * np.sin(5 * value) + 7 * np.cos(4 * value));
            count = count + 1
        temp11.append(temp1)
        temp21.append(temp2)
        
    points_x = np.array(temp11)
    points_y = np.array(temp21)
    
    
    ani = animation.FuncAnimation(fig, update_plot, frames = range(51), interval = 400, fargs = (points_x, points_y))
    
    #ani.save('result.gif', writer='imagemagick', fps = 200)
    
    plt.show()
    
    f.close()
finally:
    print("Finished.")