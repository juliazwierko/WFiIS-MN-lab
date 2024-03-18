import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig = plt.figure()	# stworzenie domyslnego obiektu figure

file = "1.txt"	# wczytanie pliku z danymi
data = np.loadtxt(file)	# do tablicy data
alfa = data[:,0]
vals = data[:,1:]

for i in np.arange(0,6):
    plt.plot(alfa, vals[:,i])


plt.grid()	# siatka pomocnicza

plt.xlabel('alfa')	# tytuly osi i wykresu
plt.ylabel('omega')

plt.savefig("wykres1.png")