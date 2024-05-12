import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig = plt.figure()	# stworzenie domyslnego obiektu figure

file = "log.txt"	# wczytanie pliku z danymi
data = np.loadtxt(file)	# do tablicy data

x = data[:, 0]	
y = data[:, 1]

plt.plot(x, y) # rysowanie wykresu
#plt.plot(t, np.cos(t), 'k-', lw=2, label='cos(t)') # wykres funkcji analitycznej

l1 = plt.legend()	# legenda
plt.grid()	# siatka pomocnicza

plt.xlabel('x')	# tytuly osi i wykresu
plt.ylabel('y')
plt.title('f1(x) = ln(x^5 + 3x^2 + x + 9)')

plt.savefig("wykres_funckji_log.png")	# zapis wykresu do pliku
