import numpy as np		# importowanie przydatnych modulow
import matplotlib.pyplot as plt

fig=plt.figure()	# stworzenie domyslnego obiektu figure

file="wynik.txt"
data = np.loadtxt(file)
it = data[:, 0]
lamda = data[:, 1]


N = 7
it = it.reshape(N, -1)
lamda = lamda.reshape(N, -1)

for j in np.arange(0 ,N):
    plt.plot(it[j], lamda[j])


plt.grid()	# siatka pomocnicza

plt.xlabel('nr iteracji')	# tytuly osi i wykresu
plt.ylabel('λ')
plt.title('Wartosci wlasne')

plt.savefig("wykres.png")	# zapis wykresu do pliku
