import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([1,2,3,4,5,6,7,8,9,10])
ypoints = np.array([1,0,0,2,10,4,40,92,352,724])

plt.title("Graph")
plt.xlabel("Number of Queens")
plt.ylabel("Number of Solutions")

plt.plot(xpoints, ypoints)
plt.show()