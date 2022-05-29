import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([10,20,30,40,50,60,70,80,90,100])
ypoints = np.array([565,606,565,531,643,531,340,303,347,565])

plt.title("Graph")
plt.xlabel("Capacity")
plt.ylabel("Max_profits")

plt.plot(xpoints, ypoints)
plt.show()