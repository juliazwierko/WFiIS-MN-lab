import numpy as np
import matplotlib.pyplot as plt

data_czebyszew = np.loadtxt('Czebyszew.txt', unpack=True)
nodes_czebyszew = np.loadtxt('x_m.txt', unpack=True)

plt.figure()

plt.plot(data_czebyszew[0], data_czebyszew[1], color='#E41A1C', linewidth=2, label='f(x) =1/(1+x^2)')
plt.plot(data_czebyszew[0], data_czebyszew[2], color='#377EB8', linewidth=2, label='w_{20}(x)')
plt.scatter(nodes_czebyszew[0], nodes_czebyszew[1], color='#4DAF4A', label='Wezly (x_m, f(x_m))')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.xlim(-5, 5)
plt.ylim(0, 1)  # Ustawienie zakresu osi y
plt.grid(True)
plt.legend(loc='lower center')

plt.savefig('czebyszew20.png')
plt.show()
