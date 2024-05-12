import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig = plt.figure()	# stworzenie domyslnego obiektu figure

file = "fun1_zad2.txt"	# wczytanie pliku z danymi
data = np.loadtxt(file)	# do tablicy data

it = data[:, 0]
x1 = data[:, 1]	
x2 = data[:, 2]
x3 = data[:, 3]
xm = data[:, 4] 

plt.plot(it, x1,'p', it, x1, 'r', it, x2,'b', it, x3, 'y', it, xm) # rysowanie wykresu
#plt.plot(t, np.cos(t), 'k-', lw=2, label='cos(t)') # wykres funkcji analitycznej

l1 = plt.legend()	# legenda
plt.grid()	# siatka pomocnicza

plt.xlabel('iteracja')	# tytuly osi i wykresu
plt.ylabel('')
plt.title('x1 = -0.9, f1(x)')

plt.savefig("wykres3.png")	# zapis wykresu do pliku
