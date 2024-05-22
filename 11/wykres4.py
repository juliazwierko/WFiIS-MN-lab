import numpy as np		
import matplotlib.pyplot as plt

fig = plt.figure()	

file = "zadanie4.txt"	
data = np.loadtxt(file)	

x = data[:, 0]	
y = data[:, 1]

plt.plot(x, y)


l1 = plt.legend()	
plt.grid()	

plt.xlabel('i')
plt.ylabel('')
plt.title('')

plt.savefig("zadanie4.png")	
