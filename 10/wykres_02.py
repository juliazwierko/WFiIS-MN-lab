import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()

file = "fun1_zad1.txt"
data = np.loadtxt(file)

x1 = data[:, 0]
f12 = data[:, 5]
f123 = data[:, 6]

plt.plot(x1, f12, 'r', label='f12')
plt.plot(x1, f123, label='f123')

plt.legend()  # legenda
plt.grid()  # siatka pomocnicza

plt.xlabel('iteracja')
plt.ylabel('')
plt.title('x1 = -0.5, f1(x)')

plt.savefig("wykres2.png")
plt.show()
