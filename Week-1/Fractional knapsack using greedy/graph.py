import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([10,20,30,40,50,60,70,80,90,100])
ypoints = np.array([533,614.158,574.579,553.256,647,547.579,473,411.615,370.04,580.051])

plt.title("Graph")
plt.xlabel("Capacity")
plt.ylabel("Max_profits")

plt.plot(xpoints, ypoints)
plt.show()