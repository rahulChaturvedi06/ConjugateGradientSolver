# -*- coding: utf-8 -*-
"""
# PYTHON SCRIPT FOR PLOTTING CONVERGENCE OF SOLVER IN REAL TIME
# AUTHOR - GAUTAM GHOSH
# DATE   - 06/07/2020
"""
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from matplotlib import style

style.use('seaborn-colorblind')

fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)

def animate(i):
    graph_data = open('../src/plotter/coords.csv','r').read()
    lines = graph_data.split('\n')
    xs = []
    ys = []
    for line in lines:
        if len(line) > 1:
            x,y = line.split(',')
            xs.append(x)
            ys.append(y)
            
    
    ax1.clear()    
    ax1.plot(xs,ys)
    
    
ani = animation.FuncAnimation(fig,animate,interval=100)
plt.show()

