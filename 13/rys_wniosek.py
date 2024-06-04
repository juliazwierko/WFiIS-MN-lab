import numpy as np
import matplotlib.pyplot as plt

# Definicja funkcji
def f(x):
    return np.log(x) * np.exp(-(x**2))

# Przygotowanie danych do wykresu
x = np.arange(0, 2.6, 0.5)
y = f(x)

# Rysowanie wykresu
plt.figure(figsize=(8, 6))
plt.plot(x, y, marker='o', linestyle='-', label='$f(x) = \ln(x) \cdot e^{-x^2}$')
plt.xlabel('$x$')
plt.ylabel('$f(x)$')
plt.title('Wykres funkcji $f(x) = \ln(x) \cdot e^{-x^2}$')
plt.grid(True)
plt.legend()
plt.xticks(np.arange(0, 2.6, 0.5))  # Ustawienie kroków na osi x
plt.savefig('rys_wniosek.png')
plt.show()
