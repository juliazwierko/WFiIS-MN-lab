import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig = plt.figure()	# stworzenie domyslnego obiektu figure

file = "fun2_zad1.txt"	# wczytanie pliku z danymi
data = np.loadtxt(file)	# do tablicy data

x1 = data[:, 0]	
# x2 = data[:, 1]
# x3 = data[:, 2]
# xm = data[:, 3] 
f12 = data[:, 5]
f123 = data[:, 6]



plt.plot(x1, f12, 'r', x1, f123) # rysowanie wykresu
#plt.plot(t, np.cos(t), 'k-', lw=2, label='cos(t)') # wykres funkcji analitycznej

l1 = plt.legend()	# legenda
plt.grid()	# siatka pomocnicza

plt.xlabel('iteracja')	# tytuly osi i wykresu
plt.ylabel('')
plt.title('x1 = 1.5, f2(x)')

plt.savefig("wykres6.png")	# zapis wykresu do pliku
