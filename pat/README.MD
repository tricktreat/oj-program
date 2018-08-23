## PAT刷题记录

### 简单模拟

+ B1001：3n+1猜想

+ B1011：A+B和C（32bit）

使用long long int，直接相加判断。

+ A1065：A+B and C(64bit)

long long int也会溢出，但是不必要使用大整数类，根据溢出后值的正负判断正溢出还是负溢出，即可与ll范围内的C进行比较。

+ B1008：数组元素循环右移

空间复杂度为常数，解决方法是不需要存储结果，直接输出结果。

+ A1042：shuffling machine

模拟洗牌机。

+ A1046：shortest distance

O(1)时间复杂度计算环形图两点间的距离。

### 查找元素

+ B1041：考试座位号

建立信息数组，数组下标为查找键。

+ A1011：world cup betting

+ A1006：sign in and sign out