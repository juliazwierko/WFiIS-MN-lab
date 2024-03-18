import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig = plt.figure()	# stworzenie domyslnego obiektu figure

file = "2.txt"	# wczytanie pliku z danymi
data = np.loadtxt(file)	# do tablicy data
alfa = data[:,0]
vals = data[:,1:]

for i in np.arange(0,6):
    plt.plot(alfa, vals[:,i])


plt.grid()	# siatka pomocnicza

plt.xlabel('x')	# tytuly osi i wykresu
plt.ylabel('u(x)')
plt.title('alfa = 0')

plt.savefig("wykres2.png")