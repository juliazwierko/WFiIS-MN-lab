import numpy as np		
import matplotlib.pyplot as plt

fig = plt.figure()	

file = "zadanie1.txt"	
data = np.loadtxt(file)	

x = data[:, 0]	
y = data[:, 1]

plt.plot(x, y)


l1 = plt.legend()	
plt.grid()	

plt.xlabel('i')
plt.ylabel('')
plt.title('k=10, sygnal zagluszony')

plt.savefig("zadanie1.png")	
