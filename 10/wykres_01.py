import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()

file = "fun1_zad1.txt"
data = np.loadtxt(file)

it = data[:, 0]
x1 = data[:, 1]
x2 = data[:, 2]
x3 = data[:, 3]
xm = data[:, 4]

plt.plot(it, x1, 'p', label='x1')
plt.plot(it, x2, 'b', label='x2')
plt.plot(it, x3, 'y', label='x3')
plt.plot(it, xm, 'r', label='xm')

plt.grid()

plt.xlabel('iteracja')
plt.ylabel('')
plt.title('x1 = -0.5, f1(x)')

plt.legend()  # dodanie legendy

plt.savefig("wykres1.png")

plt.show()
