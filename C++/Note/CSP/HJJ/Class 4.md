# Class 4 区间DP Further

- By Andy Wu

- At 浩家军

- On the night of Sept.28 $^{th}$ ,2024.

## 例题

### P7914 括号序列

#### 题意

字符串 $s$ 包含`(` ， `)` ， `*`，可以任意指定 `*` 为 `(` 或 `)` ，问合法括号序列方案数量？

#### 前缀和判断括号序列

```cpp
for(auto i : str){
    if(i == '(') sum[npos]++;
    else if(i == ')') sum[npos]--;
}
if(sum[size] == 0) Legal;
else Ilegal;
```

#### 解法

设 $dp_{i,j}$ 表示 $str_i$ ~ $str_j$ 的合法方案数量。

状态转移方程：

预处理

$$
dp_{i,i+1} = 0 \ or \ 1
$$

若 $str_i \ne ($ 或 $str_j \ne )$：

$$
dp_{i,j} = 0
$$

否则：

$$
dp_{i,j} = dp_{i+1,j-1} + \sum_{k=i+1}^{j-1}dp_{i,k}\times dp_{k+1,j}
$$

但是，上述的最后一个方程是错误的，如遇到 `(A)(B)(C)` 类型的会重复计算。

我们可以将题目分情况：

1. ()、(S) 均是符合规范的超级括号序列，其中 S 表示任意一个仅由不超过k个字符*组成的非空字符串（以下两条规则中的 S 均为此含义）；

2. 如果字符串 A 和 B 均为符合规范的超级括号序列，那么字符串 AB、ASB 均为符合规范的超级括号序列，其中 AB 表示把字符串 A 和字符串 B 拼接在一起形成的字符串；

3. 如果字符串 A 为符合规范的超级括号序列，那么字符串 (A)、(SA)、(AS) 均为符合规范的超级括号序列。

第一种情况以及第三种情况中的(A)，直接判断两端是否可以为括号，中间是否可以为S。
第三种情况，枚举断点即可。
对于第二种情况，需要枚举S，发现S的左端点是随着右端点向右移而右移的，可以用前缀和优化。

注意到ASASA，这种情况会被计算2遍，所以第二种分开计算即可。

```cpp
#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
long long n, lim;
char s[511];
long long f[511][511], S[511][511], g[511][511];

int main() {
	scanf("%lld %lld", &n, &lim);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		S[i][i - 1] = 1;
		for (int j = i; j - i + 1 <= lim && j <= n; j++)
			S[i][j] = S[i][j - 1] & (s[j] == '*' || s[j] == '?');
	}
	for (int i = n; i >= 1; i--)
		for (int j = i; j <= n; j++) {
			if ((s[i] == '(' || s[i] == '?') && (s[j] == ')' || s[j] == '?')) {
				(f[i][j] += f[i + 1][j - 1] + S[i + 1][j - 1]) %= mod;//第一种
				for (int k = i + 1; k < j - 1; k++)
					(f[i][j] += f[i + 1][k] * S[k + 1][j - 1] + f[k + 1][j - 1] * S[i + 1][k]) %= mod;//第三种
			}
			g[i][j] = f[i][j];//去重
			int sum = 0, l = i;
			for (int r = i + 1; r < j; r++) {//第二种
				(sum += f[i][r]) %= mod;
				while (!S[l][r]) {
					(sum -= f[i][l]) %= mod;
					l++;
				}
				(f[i][j] += (sum + f[i][l - 1]) * g[r + 1][j]) %= mod;
			}
		}
	printf("%lld", (f[1][n] + mod) % mod);
}
```

### Max K - Subarray

#### 题意

给定 $a_1$ ~ $a_n$ 找 $k$ 个不重叠的子序列使得和最大。

#### 题解

（为什么我没冲上电为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么为什么。。。。）

### 最长递增子序列（Longest Increasing Subsequence，LIS）

我们定义dp[i]代表原数组截止第i位，最长子序列的长度，且包括下标为i的数。那么，想求出dp[i]，主要思路就是遍历0到i-1记录的数字，如果满足nums[j]（j < i）的数小于nums[i]，那么dp[i]就可以是dp[j] + 1，遍历0到i-1找到拼接后最长的子序列长度作为dp[i]。

```cpp
for (int i = 0; i < nums.size(); i++) 
{
    for (int j = 0; j < i; j++) 
        {
        // 寻找0到i-1比当前数小的数字，试图接在后面
        if (nums[i] > nums[j]) 
        {
            // 把 nums[i] 接在后面，即可形成长度为 dp[j] + 1的递增子数列
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
```