# Class 3 区间DP

- By Andy Wu

- At 浩家军

- On the night of Sept.9$^{th}$,2024.

## Definition

所谓区间dp，指在一段区间上进行动态规划，一般做法是由长度较小的区间往长度较大的区间进行递推，最终得到整个区间的答案，而边界就是长度为1以及2的区间。

## 例题

### #1 最优矩阵乘法

#### 题意

有$n$个矩阵$A_1,A_2,...,A_n$，$A_i$的大小为$m_{i-1} \times m_i$，已知$m_0$ ~ $m_n$，求使计算量最小的用于计算所有矩阵相乘的计算顺序。

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

$$ dp_{i,j} = \operatorname{min} \{ dp_{i,k} + dp_{k+1,j}+m_{i-1} \times m_k \times m_{j} \}\ \ (i \le k \lt j) $$

时间复杂度为$\operatorname{O}(n^3)$

伪代码：

```py
for len in 1~n:
    for i in 1~(n-len+1):
        j=i+len-1
        for k in i~(j-1):
            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j])
```