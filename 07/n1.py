import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt('Newton.txt', unpack=True)
nodes = np.loadtxt('x_m.txt', unpack=True)

plt.figure()

# Wykres funkcji f(x)
plt.plot(data[0], data[1], color='#E41A1C', linewidth=2, label='f(x) = 1/(1+x^2)')
plt.ylim(-0.2, 1)

plt.plot(data[0], data[2], color='#377EB8', linewidth=2, label='w_5(x)')
plt.scatter(nodes[0], nodes[1], color='#4DAF4A', label='Węzły (x_m, f(x_m))')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.xlim(-5, 5)
plt.grid(True)
plt.legend()

plt.savefig('newton5.png')
plt.show()
