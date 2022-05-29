import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([2,4,6,8,10,12,14,16,18,20])
ypoints = np.array([15,40,70,105,145,185,225,270,320,370])

plt.title("Graph")
plt.xlabel("Number of Vertices")
plt.ylabel("Minimal Cost")

plt.plot(xpoints, ypoints)
plt.show()