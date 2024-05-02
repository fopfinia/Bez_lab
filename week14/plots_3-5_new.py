import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x1, y1 = np.loadtxt('week14/01.txt', unpack=True, dtype=int)
x2, y2 = np.loadtxt('week14/02.txt', unpack=True, dtype=int)
x3, y3 = np.loadtxt('week14/03.txt', unpack=True, dtype=int)

coefficients1 = np.polyfit(x1, y1, 5)
polynomial1 = np.poly1d(coefficients1)

coefficients2 = np.polyfit(x2, y2, 5)
polynomial2 = np.poly1d(coefficients2)

coefficients3 = np.polyfit(x3, y3, 5)
polynomial3 = np.poly1d(coefficients3)

plt.figure(figsize=(13, 7))

plt.suptitle("Time(N)", fontweight='bold')
plt.subplots_adjust(wspace=0.4, hspace=0.4)

ax = plt.subplot(2, 3, 1)
ax.scatter(x1, y1)
ax.plot(x1, polynomial1(x1), 'r')
ax.grid()
plt.title("Добавляем строго по одному элементу", fontsize=10)

ax = plt.subplot(2, 3, 2)
ax.scatter(x2, y2)
ax.plot(x2, polynomial2(x2), 'r')
ax.grid()
plt.title("Добавляем 100 элементов", fontsize=10)

ax = plt.subplot(2, 3, 3)
ax.scatter(x3, y3)
ax.plot(x3, polynomial3(x3), 'r')
ax.grid()
plt.title("Увеличиваем размер в 2 раза", fontsize=10)

ax = plt.subplot(2,3,5)
ax.grid()
ax.semilogy(x1,y1,'b',x2,y2,'g',x3,y3,'y')
plt.title('Сраваем графики с помощью логарифмического масштаба')

plt.tight_layout()
plt.show()