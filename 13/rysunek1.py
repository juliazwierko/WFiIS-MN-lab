import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()

x = [0.254886,0.178622,0.138018,0.112581,0.095101,0.082337,0.072600,0.064928,0.058724,0.053605,0.049306,0.045647,0.042494,0.039748,0.037337,0.035200,0.033295,0.031587,0.030045,0.028646,0.027371,0.026206,0.025136,0.024149,0.023239,0.022392,0.021606,0.020873,0.020190,0.019549,0.018947,0.018382,0.017848,0.017344,0.016871,0.016419,0.015993,0.015586,0.015205,0.014838,0.014486,0.014156,0.013837,0.013534,0.013243,0.012963,0.012696,0.012440,0.012194,0.011956,0.011727,0.011507,0.011295,0.011095,0.010900,0.010710,0.010523,0.010347,0.010177,0.010011,0.009849,0.009694,0.009547,0.009403,0.009258,0.009124,0.008985,0.008862,0.008734,0.008611,0.008491,0.008378,0.008265,0.008151,0.008046,0.007944,0.007844,0.007747,0.007645,0.007557,0.007464,0.007371,0.007282,0.007201,0.007120,0.007037,0.006953,0.006879,0.006806,0.006732,0.006652,0.006582,0.006516,0.006450,0.006377,0.006317,0.006252,0.006188,0.006128]

y = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

plt.plot(y, x, 'bo-')  # 'bo-' to plot points with blue circles and solid lines

plt.grid()
plt.xlabel('n')  # tytuly osi i wykresu
plt.ylabel('|c1-c1a|')
plt.savefig("zad1.png")  # zapis wykresu do pliku