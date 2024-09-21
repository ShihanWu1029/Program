# Class 3 区间DP

- By Andy Wu

- At 浩家军

- On the night of Sept.9$^{th}$,2024.

## Definition

所谓区间dp，指在一段区间上进行动态规划，一般做法是由长度较小的区间往长度较大的区间进行递推，最终得到整个区间的答案，而边界就是长度为1以及2的区间。

## 例题

### #1 最优矩阵乘法

#### 题意

有$n$个矩阵 $A_1,A_2,...,A_n$，$A_i$的大小为 $m_{i-1} \times m_i$，已知 $m_0$ ~ $m_n$，求使计算量最小的用于计算所有矩阵相乘的计算顺序。

#### 什么是矩阵乘法？

References:[【详解】矩阵乘法 - CSDN](https://blog.csdn.net/STRVE/article/details/106739349)

$$ C_{i,j} = \sum矩阵 A 的第 i 行元素\times矩阵 B 的第 j 列对应元素$$

（A 的列数必须和 B 的行数相等）

**不满足交换律，但满足结合律**

#### 题解

$A_{i\times j} \times B_{m \times n} 的计算量 = i \times n \times j (or \ m)$

有$A_i \times A_{i+1} \times ... \times A_j = B_{m_{i-1} \times {m_j}}$

**转化问题**：已知 $m_0$ ~ $m_n$，每次可以挑选相邻三个相乘即 $m_{i-1} \times m_i \times m_{i+1}$，然后把  $m_i$删去，求计算顺序使得总量最小。

设 $dp_{i,j}$ 表示计算 $A_i \times A_{i+1} \times ... \times A_j$ 的最小计算量

答案即为 $dp_{1,n}$

状态转移方程：

$$ dp_{i,j} = min \{ dp_{i,k} + dp_{k+1,j}+m_{i-1} \times m_k \times m_{j} \}\ \ (i \le k \lt j) $$

时间复杂度为 $O(n^3)$

伪代码：

```py
for len in 1~n:
    for i in 1~(n-len+1):
        j=i+len-1
        for k in i~(j-1):
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j])
```

### #2 石子合并

From Atcoder dp_n

#### 题意

在一个圆形操场的四周摆放着 $n$ 堆石子。现要将石子有次序地合并成一堆。规定每次只能选相邻的 $2$ 堆石子合并成新的一堆，并将新的一堆石子数记为该次合并的得分。试设计一个算法，计算出将 $n$ 堆石子合并成一堆的最小得分和最大得分。
对于给定 $n$ 堆石子,计算合并成一堆的最小得分和最大得分。

#### 题解

这题的难点是：如果将环形转换为直线

其核心思想就是：通过将数量变为 $2n-1$ 来转换成直线问题。

![Explanation](../../../Resource/Class%203%20区间DP%20-%201.png)

1. 我们为了将环形变为直线，必须规定转动顺序，这里采用逆时针转动，且以 $i$ 作为起点，$j$ 作为终点。(右下图）

2. 当规定好终点了，那么这环形有4种情况，我们求在这四种情况下最下的。(右上图）

3. 关于转换成直线，比如存在 a(0) -> b(1) -> c(2) -> d(3) 与 d(3) -> a(4) -> b(5) -> c(6)。

　　第一条是 i=0,j=3的数组，第二条是 i=3,j=6 的数组。 这样，我们就不用返回去计算了( 3->0->1->2 ???)。

4. 四种情况分别是数组中的四行，每行最后一个代表遍历的结果，我们最后只需要遍历这四个值，找到最小值即可。

代码：
```cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int Arr[300],Sum[300];
int Min[300][300], Max[300][300];
int main() {
    int n;
    cin >> n;

    // 初始化数组
    for (int i = 1; i <= n; i++) {
        cin >> Arr[i];
        Arr[i + n] = Arr[i];
    }

    // 计算最大和
    for (int i = 1; i <= 2 * n; i++) {
        Sum[i] = Sum[i - 1] + Arr[i];
    }

    // 开始递归循环
    for (int i = 2 * n-1; i >= 1; i--) {
        for (int j = i + 1; j < i + n; j++) {
            Min[i][j] = INF;
            for (int k = i; k < j; k++) {
                Min[i][j] = min(Min[i][j], Min[i][k] + Min[k + 1][j] + Sum[j] - Sum[i - 1]);
                Max[i][j] = max(Max[i][j], Max[i][k] + Max[k + 1][j] + Sum[j] - Sum[i - 1]);
            }
        }
    }

    // 遍历找到最大与最小值
    int MaxValue = 0, MinValue = INF;
    for (int i = 1; i <= n; i++) {
        MaxValue = max(MaxValue, Max[i][i + n - 1]);
        MinValue = min(MinValue, Min[i][i + n - 1]);
    }

    cout << MinValue << endl << MaxValue << endl;

}
```

$etc.$