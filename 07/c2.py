import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('Czebyszew.txt', unpack=True)
nodes = np.loadtxt('x_m.txt', unpack=True)

plt.figure()

plt.plot(data[0], data[1], color='#E41A1C', linewidth=2, label='f(x) =1/(1+x^2)')
plt.plot(data[0], data[2], color='#377EB8', linewidth=2, label='w_{10}(x)')
plt.scatter(nodes[0], nodes[1], color='#4DAF4A', label='Wezly (x_m, f(x_m))')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.xlim(-5, 5)
plt.grid(True)
plt.legend()

plt.savefig('czebyszew10.png')
plt.show()
