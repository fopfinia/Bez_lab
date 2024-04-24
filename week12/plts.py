import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x1, y1 = np.loadtxt('week12/11.txt', unpack=True, dtype=int)
x2, y2 = np.loadtxt('week12/12.txt', unpack=True, dtype=int)

coefficients1 = np.polyfit(x1, y1, 1)
polynomial1 = np.poly1d(coefficients1)

coefficients2 = np.polyfit(x2, y2, 1)
polynomial2 = np.poly1d(coefficients2)

plt.figure(figsize=(13, 7))

plt.suptitle("Time(N)", fontweight='bold')
plt.subplots_adjust(wspace=0.4, hspace=0.4)

ax = plt.subplot(2, 2, 1)
ax.scatter(x1, y1)
ax.plot(x1, polynomial1(x1), 'r')
ax.grid()
plt.title("Добавляем элементs", fontsize=10)

ax = plt.subplot(2, 2, 2)
ax.scatter(x2, y2)
ax.plot(x2, polynomial2(x2), 'r')
ax.grid()
plt.title("Читаем элементs", fontsize=10)


#ax = plt.subplot(2,2,3)
#ax.grid()
#ax.semilogy(x1,y1,'b',x2,y2,'g')
#plt.title('Сраваем графики с помощью логарифмического масштаба')

plt.tight_layout()
plt.show()