import matplotlib.pyplot as plt
import numpy as np

# Funkcje do narysowania
def first_function(x):
    return 1 / (1 + x**2)

def second_function(x):
    return np.cos(2 * x)

# Dane z plików tekstowych (zakładając, że pliki mają odpowiedni format)
first_fun_data = np.loadtxt("pierwsza_funkcja.txt")
second_fun_data = np.loadtxt("druga_funkcja.txt")
first_points_data = np.loadtxt("pierwsza_punkty.txt")
second_points_data = np.loadtxt("druga_punkty.txt")

# Ustawienia wykresu dla pierwszej funkcji
plt.figure(figsize=(8, 6))
for i, n in enumerate([5, 6, 10, 20]):
    plt.plot(first_fun_data[:, 0], first_fun_data[:, 1], label=f"n={n}")
plt.scatter(first_points_data[:, 0], first_points_data[:, 1], marker='o', label="wezly")
plt.plot(first_fun_data[:, 0], first_function(first_fun_data[:, 0]), label="f(x)")
plt.title("1/(1+x^{2})")
plt.xlabel("x")
plt.legend()
plt.savefig("wykres1.png")  # Zapisanie wykresu 1 do pliku PNG
plt.show()

# Ustawienia wykresu dla drugiej funkcji
plt.figure(figsize=(8, 6))
for i in range(3):
    plt.plot(second_fun_data[:, 0], second_fun_data[:, 1], label=f"n={6 if i == 0 else (7 if i == 1 else 14)}")
plt.scatter(second_points_data[:, 0], second_points_data[:, 1], marker='o', label="wezly")
plt.plot(second_fun_data[:, 0], second_function(second_fun_data[:, 0]), label="f(x)")
plt.title("cos(2x)")
plt.xlabel("x")
plt.legend()
plt.savefig("wykres2.png")  # Zapisanie wykresu 2 do pliku PNG
plt.show()
