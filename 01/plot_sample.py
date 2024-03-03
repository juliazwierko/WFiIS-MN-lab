import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()

# Wczytanie danych z pliku
file = "out.txt"
data = np.loadtxt(file)
t = data[:, 0]
x = data[:, 1]

# Rysowanie wykresu punktów
plt.plot(t, x, 'bo', lw=2, label='x(t), h=0.1')

# Dodanie prostej linii łączącej punkty (w kolorze różowym) z opisem
plt.plot(t, x, 'pink', lw=2, label='cos(t)')

l1 = plt.legend()
plt.grid()

plt.xlabel('t')
plt.ylabel('x(t)')
plt.title('wychylenie x(t)')

plt.savefig("zad1.png")
plt.show()
