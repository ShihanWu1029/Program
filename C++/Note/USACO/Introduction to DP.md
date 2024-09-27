# Introduction to DP

- 2024/9/13 16:00 ~ 17:30

- Andy Wu

RP++!

## Fibonacci sequence

Definition: $f(n)=f(n-1)+f(n-2)$

Using a tree to calculate:

e.g. $f(4)=f(3)+f(2)$

$f(3)=f(2)+f(1),f(2)=1$

$f(2)=1,f(1)=1,/,/$

## Coin Problem

For example, you need to take out 253 $, and you want to take it in the minimun number of money paper.

Normal Way: 100+100+50+3 (greedy algorithm)

But if there's only particular type of money, it can't work.

e.g.

only 1,3,4$ of money

you need 10$

**using dp to solve it:**

You can see the problem like this: $f(10)=\operatorname{min}\{f(10-1),f(10-3),f(10-4)\}+1$

And so, it is easy to find that $f(n)=\operatorname{min}\{f(n-1),f(n-3),f(n-4)\}+1$

Then, from $f(1)$ to calculate each term.

$f(1)=1,f(2)=2,f(3)=1,f(4)=1, etc.$

Use c++ to solve, it can show like below:

```cpp
#include<bits/stdc++.h> 
using namespace std; 

int main() { 
    int n; 
    cin >> n; 
    const int INF = INT32_MAX; 
    int coins[3] = { 1, 3, 4 }; 
    int value[n + 1]; 
    
    value[0] = 0; 
    for (int x = 1; x <= n; x++) { 
        value[x] = INF; 
        for (auto c : coins) { 
            if (x - c >= 0) { 
                value[x] = min(value[x], value[x - c] + 1); 
            } 
        } 
    } 
}
```

Sometimes we need to find the total number of ways to take out such money.

Then the equation will be like this:

$ f(n)=f(n-1)+f(n-3)+f(n-4)$

Moreover, we may need to find how does the way work.

Then the code tranforms like below:

```cpp
int first[N];
value[0] = 0; 
for (int x = 1; x <= n; x++) { 
    value[x] = INF; 
    for (auto c : coins) { 
        if (x-c >= 0 && value[x-c]+1 < value[x]) { 
            value[x] = value[x-c]+1; 
            first[x] = c; 
        } 
    }
}
```

## Longest increasing subsequence

**Core:** 

```cpp
\\Define a array to record the len of the longest increasing subsequence before and at this point.

int f[n]={0};

for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<a[i] && f[j]+1>f[i])
            f[i]=f[j]+1;
    }
}
```

$etc.$

## Paths in a grid

A grid with weight in every unit square.

You set off from the beginning point and want to arrive at the destination with the lowest sum of weights.

~~(Just like a maze lol.)~~

Assume that the grid was record in the array $map[\ ][\ ]$.

The DP equation is like this: 

```c++
Sum[x][y]=min(Sum[x-1][y],Sum[x][y-1])+map[x][y];
```

