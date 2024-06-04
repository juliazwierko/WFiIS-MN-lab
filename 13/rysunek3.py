import numpy as np	
import matplotlib.pyplot as plt

fig = plt.figure()

x = [0.915146,0.294093,0.108139,0.104861,0.076642,0.055665,0.043693,0.035004,0.028648,0.023886,0.020217,0.017332,0.015023,0.013147,0.011601,0.010313,0.009228,0.008305,0.007515,0.006832,0.006238,0.005718,0.005261,0.004856,0.004496,0.004175,0.003887,0.003628,0.003394,0.003182,0.002989,0.002813,0.002653,0.002505,0.002370,0.002245,0.002130,0.002023,0.001925,0.001833,0.001748,0.001669,0.001595,0.001525,0.001460,0.001399,0.001342,0.001288,0.001238,0.001190,0.001145,0.001103,0.001063,0.001025,0.000989,0.000955,0.000922,0.000892,0.000862,0.000835,0.000808,0.000783,0.000759,0.000736,0.000714,0.000693,0.000673,0.000654,0.000635,0.000617,0.000601,0.000584,0.000569,0.000554,0.000539,0.000526,0.000512,0.000499,0.000487,0.000475,0.000464,0.000453,0.000442,0.000432,0.000422,0.000412,0.000403,0.000394,0.000386,0.000377,0.000369,0.000361,0.000353,0.000346,0.000339,0.000332,0.000325,0.000319,0.000313]
y = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100]

plt.plot(y, x, 'bo-')

l1 = plt.legend()	
plt.grid()

plt.xlabel('n')	# tytuly osi i wykresu
plt.ylabel('|c2-c2a|')


plt.savefig("zad2b.png")	# zapis wykresu do pliku
