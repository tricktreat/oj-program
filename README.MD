## LeetCode题目

### [leetcode55](https://leetcode.com/problems/jump-game/)

动态规划

### [leetcode94](https://leetcode.com/problems/binary-tree-inorder-traversal/)

中序遍历。

### [leetcode98](https://leetcode.com/problems/validate-binary-search-tree/)

BST判断，中序遍历

### [leetcode99](https://leetcode.com/problems/recover-binary-search-tree/)

交换节点，满足二叉搜索树。中序遍历的两种实现。（问题的本质是在序列中找到两个元素，交换位置以后使得序列满足升序。二叉搜索树的中序序列恰好是升序的，所以交换已对元素调整为升序序列即可使二叉搜索树合理）

### [leetcode100](https://leetcode.com/problems/same-tree/)

判断两个二叉树是否相等，同构二叉树判断代码类似。

### [leetcode105](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

前序遍历和中序遍历构建二叉树。

### [leetcode106](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

后序遍历和中序遍历构建二叉树。

### [leetcode112](https://leetcode.com/problems/path-sum/)

二叉树某条从根节点到叶节点的路径权重和是否等于指定数值。

### [leetcode113](https://leetcode.com/problems/path-sum-ii/)

在112的基础上输出所有满足条件的路径。南大开放日2017年上机题。

### [leetcode437](https://leetcode.com/problems/path-sum-iii/)

在113的基础上放松了一下条件，路径可以为自上而下的任意一条路径，不一定要从根到叶。保存序列和，dfs过程中判断指定数值与当前序列和和历史序列和之差是否相等。

## pat题目

### [pat1004](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)

树的每一层叶子节点个数。可以用结构体来记录节点层数（构造一棵树），也可以在层序遍历

## 字符串

### [hdu1711](https://vjudge.net/problem/hdu-1711)

字符串匹配，kmp算法，得到首次匹配的头索引。

### [poj3461](https://vjudge.net/problem/poj-3461)

字符串匹配，kmp算法，得到匹配子串的个数

## 贪心算法

### [poj3617](https://vjudge.net/problem/poj-3617)

### [poj3069](https://vjudge.net/problem/poj-3069)

### [poj3253](https://vjudge.net/problem/poj-3253)

哈夫曼，使用优先队列

## 图

### [poj3723](https://vjudge.net/problem/poj-3723)

最小生成树，kruskal算法+并查集

### [poj3255](https://vjudge.net/problem/poj-3255)

次短路径，更新最短路径和次短路径。次短距离要么是最短距离+cost，要么是次短距离加上cost

## dfs

### [poj2386](https://vjudge.net/problem/poj-2386)

满足条件下状态转移。 

### [poj1321](https://vjudge.net/problem/poj-1321)

类似于n后问题，主要是构造出约束函数，

## bfs

### [poj3287](https://vjudge.net/problem/poj-3287)

bfs过程中对出界进行判断，对遍历的层数进行记录（设置结尾标记变量或者结构体记录节点层数或者数组记录层数，后面两种方法均是于父节点建立+1递推关系）

## 动态规划

### [zoj1074](https://vjudge.net/problem/zoj-1074)

最大子矩阵和，类似于最大子串和，二维压缩成一维。

### [uva116](https://vjudge.net/problem/uva-116)

多段图的决策问题

### [uva111](https://vjudge.net/problem/uva-111)

最长递增子序列的最长公共子序列解法，或者构造DAG来dp

### [uva103](https://vjudge.net/problem/uva-103)

矩形嵌套

### [uva10425](https://vjudge.net/problem/uva-10425)

最长公共子序列

### [uva674](https://vjudge.net/problem/uva-674)

类似于完全背包问题，f[i,v]：使用前i种硬币恰好组成面值v的方法总数，f[i,v]包含了只使用前i-1种硬币组成面值v的方法种数，另外也包含了使用前i种硬币组成面值v-c[i]的方法种数，所以状态转移方程为：f[i,v]=f[i-1,v]+f[i,v-c[i]]

### [uva10003](https://vjudge.net/problem/uva-10003)

区间dp，切木头

### [uva10131](https://vjudge.net/problem/uva-10131)

变种的最大递增子序列，多关键字严格排序

### [uva10066](https://vjudge.net/problem/uva-10066)

最长公共子序列

### [uva10192](https://vjudge.net/problem/uva-10192)

最长公共子序列

### [uva357](https://vjudge.net/problem/uva-357)

同uva674

### [uva562](https://vjudge.net/problem/uva-562)

0/1背包问题的变种，体积（限制）和价值（最大）同一意义，纯粹表示填充的越满越好。目标是两个划分差距越小，那么其中较少的划分必须尽量接近总数的一半。

### [uva348](https://vjudge.net/problem/uva-348)

矩阵链乘法，区间dp

### [uva624](https://vjudge.net/problem/uva-624)

类似于uva562，歌曲尽量充满磁带。需要考虑如何有效记录结果以及打印结果需要注意循环的顺序

### [uva10130](https://vjudge.net/problem/uva-10130)

0/1背包问题

### [hdu2602](https://vjudge.net/problem/hdu-2602)

0/1背包问题，模板题

### [uva531](https://vjudge.net/problem/uva-531)

最长公共子序列，打印时遇到的坑，先判断dp不相等的递归，在判断dp相等的递归。

### [uva10465](https://vjudge.net/problem/uva-10465)

完全背包问题，背包无关顺序，是否要装满的区别在于初始化。装满要求dp[0]=0，其他为-INF，而不要求装满所有的都初始化为0。注意与硬币拆分问题uva674的状态转移和初始化的区别

### [uva10285](https://vjudge.net/problem/uva-10285)

最长递增子序列，二维

### [uva437](https://vjudge.net/problem/uva-437)

与uva103解法相同，构造DAG（将相互关系存储在矩阵中，如uva103）可以，也可以直接进行关系比较（本题就是）。与LIS不同的是，LIS只需要考虑当前阶段的之间阶段，而嵌套问题（无固定起点和终点）需要考虑所有的状态。

### [uva10404](https://vjudge.net/problem/uva-10404)（有点难以理解）

如果石头个数为n时，先下子者取胜即d[n]=1，那么当有n+m[i]个石头后下子者取胜即d[n+m[i]]=0，状态转移方程为：f[n]=f[n-m[i]]==0?1:0（站在前者的角度，如果k种选择都到达不了每一个为0的阶段（即前者输的阶段）那么当前阶段也是输）

### [uva620](https://vjudge.net/problem/uva-620)

递归

### [uva825](https://vjudge.net/problem/uva-825)

动态规划，注意输入

### [uva10069](https://vjudge.net/problem/uva-10069)

dp，哎状态转移方程没想出来。定义大整数结构体

### [uva10534](https://vjudge.net/problem/uva-10534)

最长递增子序列、最短递增子序列。dp[O(n^2)]以外的另外一种算法[O(nlgn)]

### [uva10051](https://vjudge.net/problem/uva-10051)

最长递增子序列，每一个元素多个状态，就可以看成多个元素，注意多个状态的同一个元素的不同点要在前后的关系比较中使用到，避免同一元素的多次使用。这里在dp中比较元素（拓展）的weight可以使得同一个元素（原意）只用一次。

### [uva10651](https://vjudge.net/problem/uva-10651) 类似的题多做做

状态压缩dp，用整数（二进制形式与状态有着联系）表示动态规划的状态。使用二进制运算改变状态的二进制形式，建立状态转移方程。

### [poj3311](https://vjudge.net/problem/POJ-3311)

状态压缩dp。旅行商问题+Floyd多源最短路径

### [uva590](https://vjudge.net/problem/uva-590)

航班和城市。dp[i][j]为第i天到达第j个城市的最小cost，它等于前一天到达某一城市m（非i城市）的最小花费加上b[i-1][m][j]（第i-1天m到i城市的价格）。初始化很重要，要保证不合理的状态不影响后续状态的更新，要保证状态的初始值不影响后面的更新。

### [uva10306](https://vjudge.net/problem/uva-10306)

二维完全背包问题。仅仅是dp数组多了一维而已，更新时多了一层循环嵌套
