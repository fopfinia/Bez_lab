import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x = np.array([100,100,100,100,100,1000,1000,1000,1000,1000,2000,2000,2000,2000,2000,4000,4000,4000,4000,4000,6000,6000,6000,6000,6000,8000,8000,8000,8000,8000,10000,10000,10000,10000,10000])
y = np.array([261254/10000,324570/10000,343023/10000,282159/10000,300400/10000,38185/100,50880/100,48836/100,38151/100,42362/100,243601/20,221721/20,205325/20,201726/20,263764/20,393566/10,405969/10,476171/10,426570/10,447673/10,852640/10,805228/10,873357/10,804198/10,834949/10,1670377/10,1662049/10,1552380/10,1576686/10,1623362/10,2525101/10,2373432/10,2354928/10,2300080/10,2323012/10])

coefficients = np.polyfit(x, y, 20)
polynomial = np.poly1d(coefficients)

plt.scatter(x, y)
plt.plot(x, polynomial(x), color='red')
plt.xlabel('Количество элементов в массиве')
plt.ylabel('Время поиска элемента (мкс)')
plt.grid()
plt.show()