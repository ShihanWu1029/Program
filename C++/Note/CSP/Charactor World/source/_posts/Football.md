---
title: Football
date: 2023-08-09 20:28:41
tags: CSP-J
categories: 题解
---
### AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main() {
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i ++) {
        if (!i || s[i] != s[i-1]) cnt = 1;
        else {
            cnt ++;
            if (cnt >= 7) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}

```