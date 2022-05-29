import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([10,20,30,40,50,60,70,80,90,100])
ypoints = np.array([533,610,533,533,647,533,342,305,349,568])

plt.title("Graph")
plt.xlabel("Capacity")
plt.ylabel("Max_profits")

plt.plot(xpoints, ypoints)
plt.show()