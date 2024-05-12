import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('Newton.txt', unpack=True, skiprows=1002, max_rows=1001)
nodes = np.loadtxt('x_m.txt', unpack=True, skiprows=7, max_rows=11)

plt.figure()


plt.plot(data[0], data[1], color='#E41A1C', linewidth=2, label='f(x) = 1/(1+x^2)')
plt.plot(data[0], data[2], color='#377EB8', linewidth=2, label='w_10(x)')

plt.scatter(nodes[0], nodes[1], color='#4DAF4A', label='Węzły (x_m, f(x_m))')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.xlim(-5, 5)
plt.grid(True)
plt.legend(loc='upper center')

plt.savefig('newton10.png')
plt.show()
