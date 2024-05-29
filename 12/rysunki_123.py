import matplotlib.pyplot as plt

# Dane dla zestawu 1
data_m0_k1 = [
    4.934802, 0.876090, 2.211353, 1.976022, 2.001829,
    1.999900, 2.000004, 2.000000, 2.000000, 2.000000,
    2.000000, 2.000000, 2.000000, 2.000000, 2.000000,
    2.000000, 2.000000, 2.000000, 2.000000, 2.000000,
    2.000000, 2.000000, 2.000000, 2.000000, 2.000000,
    2.000000, 2.000000, 2.000000, 2.000000, 2.000000,
    2.000000
]

# Dane dla zestawu 2
data_m1_k1 = [
    10.335426, 0.134769, 3.730357, 3.073189, 3.146894,
    3.141298, 3.141605, 3.141592, 3.141593, 3.141593,
    3.141593, 3.141593, 3.141593, 3.141593, 3.141593,
    3.141593, 3.141593, 3.141593, 3.141593, 3.141593,
    3.141593, 3.141593, 3.141593, 3.141593, 3.141593,
    3.141593, 3.141593, 3.141593, 3.141593, 3.141593,
    3.141593
]

plt.plot(range(len(data_m0_k1)), data_m0_k1, label="m = 0, k = 1", color='magenta')
plt.plot(range(len(data_m1_k1)), data_m1_k1, label="m = 1, k = 1", color='cyan')
plt.xlabel('Numer węzła')
plt.ylabel('Wartość całki')
plt.title('Porównanie wartości całki dla m = 0, k = 1 oraz m = 1, k = 1')
plt.legend()
plt.grid(True)
plt.savefig('rysunek4.png')

plt.clf()  # Wyczyść bieżący wykres

# Dane dla zestawu 3
data_m5_k5_new = [
    1.4800133008, 0.0993498812, 0.0025142038, 0.0001567897, 0.0000097938
]

plt.plot(range(len(data_m5_k5_new)), data_m5_k5_new, label="m = 5, k = 5", color='magenta')
plt.xlabel('Liczba węzłów (n)')
plt.ylabel('|C - I|')
plt.title('Zależność |C - I| od liczby węzłów (m = 5, k = 5)')
plt.legend()
plt.grid(True)
plt.savefig('rysunek5.png')
