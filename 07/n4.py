import numpy as np
import matplotlib.pyplot as plt

data_newton = np.loadtxt('Newton.txt', unpack=True, skiprows=3006, max_rows=1001)
nodes_newton = np.loadtxt('x_m.txt', unpack=True, skiprows=36, max_rows=20)

plt.figure()

plt.plot(data_newton[0], data_newton[1], color='#E41A1C', linewidth=2, label='f(x) =1/(1+x^2)')
plt.plot(data_newton[0], data_newton[2], color='#377EB8', linewidth=2, label='w_{20}(x)')
plt.scatter(nodes_newton[0], nodes_newton[1], color='#4DAF4A', label='Wezly (x_m, f(x_m))')

plt.xlabel('x')
plt.ylabel('f(x)')
plt.xlim(-5, 5)
plt.ylim(-60, 10)
plt.grid(True)
plt.legend(loc='lower center')
 
plt.savefig('newton20.png')
plt.show()
