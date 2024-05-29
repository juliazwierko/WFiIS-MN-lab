import matplotlib.pyplot as plt

# Dane dla zestawu 1 (m = 0, k = 1)
x1 = [11, 21, 51, 101, 201]
y1 = [0.0001095173, 0.0000067844, 0.0000001733, 0.0000000108, 0.0000000007]

# Dane dla zestawu 2 (m = 1, k = 1)
x2 = [11, 21, 51, 101, 201]
y2 = [0.0001720294, 0.0000106570, 0.0000002721, 0.0000000170, 0.0000000011]

# Dane dla zestawu 3 (m = 5, k = 5)
x3 = [11, 21, 51, 101, 201]
y3 = [1.4800133008, 0.0993498812, 0.0025142038, 0.0001567897, 0.0000097938]

# Wykresy dla każdego zestawu danych

#plt.plot(x1, y1, label="m = 0, k = 1", color='blue')

plt.plot(x3, y3, label="m = 5, k = 5", color='red')
#plt.plot(x2, y2, label="m = 1, k = 1", color='green')

plt.xlabel('Liczba węzłów (n)')
plt.ylabel('|C - I|')
plt.title('Zależność |C - I| od liczby węzłów')
plt.legend()
plt.grid(True)

# Zwiększenie precyzji osi x
plt.xticks(range(0, 211, 20))

plt.savefig('rys5.png')

plt.show()
