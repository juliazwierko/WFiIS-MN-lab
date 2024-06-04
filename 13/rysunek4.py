import numpy as np	
import matplotlib.pyplot as plt

fig = plt.figure()

x = [0.089935,0.072124,0.032680,0.008442,0.000480,0.001924,0.001225,0.000481,0.000106]
y = [2,3,4,5,6,7,8,9,10]
plt.plot(y, x, 'bo-')

l1 = plt.legend()	
plt.grid()

plt.xlabel('n')	# tytuly osi i wykresu
plt.ylabel('|c3-c3a|')


plt.savefig("zad4.png")	# zapis wykresu do pliku
