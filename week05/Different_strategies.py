import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

x1 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               30000,
               30000,
               30000,
               30000,
               30000,
               50000,
               50000,
               50000,
               50000,
               50000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000])
y1 = np.array([7626648/100000000,
               7599899/100000000,
               7578982/100000000,
               7576185/100000000,
               7568950/100000000,
               4432926/10000000,
               4412898/10000000,
               4389564/10000000,
               4420851/10000000,
               4428807/10000000,
               4187755/1000000,
               4156110/1000000,
               4188677/1000000,
               4192028/1000000,
               4197074/1000000,
               12281166/1000000,
               12341068/1000000,
               12783653/1000000,
               12623503/1000000,
               12613561/1000000,
               21078201/1000000,
               20923274/1000000,
               21085721/1000000,
               21231555/1000000,
               21036510/1000000,
               3717936/100000,
               3801249/100000,
               3735473/100000,
               3723827/100000,
               3737987/100000,
               4649644/100000,
               4672260/100000,
               4637052/100000,
               4649852/100000,
               4670596/100000])

x2 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               20000,
               20000,
               20000,
               20000,
               20000,
               40000,
               40000,
               40000,
               40000,
               40000,
               55000,
               55000,
               55000,
               55000,
               55000,
               70000,
               70000,
               70000,
               70000,
               70000,
               70000,
               70000,
               70000,
               70000,
               70000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000])
y2 = np.array([5125438/100000000,
               5123380/100000000,
               5158801/100000000,
               5134722/100000000,
               5146107/100000000,
               11583208/100000000,
               11663753/100000000,
               11521353/100000000,
               11495172/100000000,
               11479982/100000000,
               6770842/10000000,
               6754799/10000000,
               6671605/10000000,
               6731163/10000000,
               6697070/10000000,
               12470316/10000000,
               12289198/10000000,
               12375288/10000000,
               12348452/10000000,
               12322578/10000000,
               26583977/10000000,
               26552535/10000000,
               26725902/10000000,
               26522417/10000000,
               26904387/10000000,
               3429618/1000000,
               3565295/1000000,
               3531130/1000000,
               3549873/1000000,
               3462105/1000000,
               33131847/10000000,
               33100728/10000000,
               32974097/10000000,
               33094587/10000000,
               32844435/10000000,
               3438608/1000000,
               3521693/1000000,
               3467499/1000000,
               3569364/1000000,
               3521283/1000000,
               4858700/1000000,
               4920372/1000000,
               4875768/1000000,
               4828600/1000000,
               4807247/1000000,
               6082590/1000000,
               6202100/1000000,
               6058862/1000000,
               6104885/1000000,
               6070612/1000000])

x3 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               30000,
               30000,
               30000,
               30000,
               30000,
               50000,
               50000,
               50000,
               50000,
               50000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000])
y3 = np.array([6898672/100000000,
               7215041/100000000,
               6659216/100000000,
               7035461/100000000,
               6961846/100000000,
               3482925/10000000,
               3492955/10000000,
               3675361/10000000,
               3475209/10000000,
               3590902/10000000,
               4781316/1000000,
               4920626/1000000,
               4864628/1000000,
               4811779/1000000,
               4819447/1000000,
               14535614/1000000,
               14459704/1000000,
               14508686/1000000,
               14648271/1000000,
               14648011/1000000,
               2473489/100000,
               2406421/100000,
               2516470/100000,
               2463014/100000,
               2434256/100000,
               3858548/100000,
               3995859/100000,
               3924365/100000,
               3953912/100000,
               3904931/100000,
               4797263/100000,
               5063733/100000,
               4840737/100000,
               4863400/100000,
               4914005/100000])

x4 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               30000,
               30000,
               30000,
               30000,
               30000,
               50000,
               50000,
               50000,
               50000,
               50000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000
               ])
y4 = np.array([5466146/100000000,
               5445851/100000000,
               5570840/100000000,
               5527419/100000000,
               5492359/100000000,
               11621482/100000000,
               11724261/100000000,
               11645099/100000000,
               11656016/100000000,
               11536236/100000000,
               6892336/10000000,
               6983033/10000000,
               7297257/10000000,
               6795858/10000000,
               7093211/10000000,
               18353273/10000000,
               18437988/10000000,
               18542075/10000000,
               18339860/10000000,
               18192482/10000000,
               3482137/1000000,
               3427988/1000000,
               3099974/1000000,
               3163810/1000000,
               3336026/1000000,
               5149281/1000000,
               4823515/1000000,
               5153680/1000000,
               4930679/1000000,
               4900807/1000000,
               6013545/1000000,
               6133979/1000000,
               6187734/1000000,
               6051973/1000000,
               6059993/1000000])

x5 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               30000,
               30000,
               30000,
               30000,
               30000,
               50000,
               50000,
               50000,
               50000,
               50000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000])
y5 = np.array([7030523/100000000,
               7221304/100000000,
               6691541/100000000,
               7043845/100000000,
               6757242/100000000,
               3543596/10000000,
               3589643/10000000,
               3802212/10000000,
               3574595/10000000,
               3721683/10000000,
               3575070/1000000,
               3635261/1000000,
               3702385/1000000,
               3678734/1000000,
               3662948/1000000,
               11972020/1000000,
               11990710/1000000,
               11863808/1000000,
               11972478/1000000,
               12084343/1000000,
               4547129/100000,
               4652152/100000,
               4614826/100000,
               4459472/100000,
               4535524/100000,
               8759673/100000,
               8842897/100000,
               8651578/100000,
               8630348/100000,
               8565180/100000,
               11610920/100000,
               11591949/100000,
               11561231/100000,
               11563097/100000,
               11703916/100000])

x6 = np.array([100,
               100,
               100,
               100,
               100,
               1000,
               1000,
               1000,
               1000,
               1000,
               10000,
               10000,
               10000,
               10000,
               10000,
               30000,
               30000,
               30000,
               30000,
               30000,
               50000,
               50000,
               50000,
               50000,
               50000,
               80000,
               80000,
               80000,
               80000,
               80000,
               100000,
               100000,
               100000,
               100000,
               100000])
y6 = np.array([5469787/100000000,
               5504231/100000000,
               5456719/100000000,
               5458925/100000000,
               5415233/100000000,
               11692891/100000000,
               11725319/100000000,
               11687051/100000000,
               11647022/100000000,
               11782667/100000000,
               6939325/10000000,
               6873795/10000000,
               6879894/10000000,
               6864255/10000000,
               6807553/10000000,
               18706067/10000000,
               18544324/10000000,
               18756675/10000000,
               18574109/10000000,
               18660801/10000000,
               3156641/1000000,
               3196320/1000000,
               3125957/1000000,
               3218746/1000000,
               3371506/1000000,
               5046176/1000000,
               5025149/1000000,
               4968176/1000000,
               5019868/1000000,
               4850036/1000000,
               6282393/1000000,
               6231089/1000000,
               6288511/1000000,
               6253697/1000000,
               6290962/1000000])

coefficients1 = np.polyfit(x1, y1, 1)
polynomial1 = np.poly1d(coefficients1)

coefficients2 = np.polyfit(x2, y2, 1)
polynomial2 = np.poly1d(coefficients2)

coefficients3 = np.polyfit(x3, y3, 1)
polynomial3 = np.poly1d(coefficients3)

coefficients4 = np.polyfit(x4, y4, 1)
polynomial4 = np.poly1d(coefficients4)

coefficients5 = np.polyfit(x5, y5, 4)
polynomial5 = np.poly1d(coefficients5)

coefficients6 = np.polyfit(x6, y6, 1)
polynomial6 = np.poly1d(coefficients6)

plt.figure(figsize=[13, 7])
plt.suptitle("Зависимость времени поиска пары от количества элементов в массиве, равномерности их распределения и стратегии поиска", fontweight='bold')
plt.subplots_adjust(wspace= 0.4, hspace = 0.4)

plt.subplot(3,2,1)
plt.scatter(x1, y1)
plt.plot(x1, polynomial1(x1), 'r')
plt.grid()
plt.title("Стратегия А: равномерное распределение", fontsize=10)

plt.subplot(3,2,2)
plt.scatter(x2, y2)
plt.plot(x2, polynomial2(x2), 'b')
plt.grid()
plt.title("Стратегия А: неравномерное распределение", fontsize=10)

plt.subplot(3,2,3)
plt.scatter(x3, y3)
plt.plot(x3, polynomial3(x3), '--r')
plt.grid()
plt.title("Стратегия B: равномерное распределение", fontsize=10)

plt.subplot(3,2,4)
plt.scatter(x4, y4)
plt.plot(x4, polynomial4(x4), '--b')
plt.grid()
plt.title("Стратегия B: неравномерное распределение", fontsize=10)

plt.subplot(3,2,5)
plt.scatter(x5, y5)
plt.plot(x5, polynomial5(x5), '-.r')
plt.grid()
plt.title("Стратегия C: равномерное распределение", fontsize=10)

plt.subplot(3,2,6)
plt.scatter(x6, y6)
plt.plot(x6, polynomial6(x6), '-.b')
plt.grid()
plt.title("Стратегия C: неравномерное распределение", fontsize=10)

plt.show()