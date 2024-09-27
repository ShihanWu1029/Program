---
title: Spell Checker
date: 2023-08-09 20:05:42
tags: CSP-S & CSP-J
categories: 题解
---

## AC代码

- STL版本
```cpp
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>

using namespace std;

map<string, int> dictionary;
set<size_t> lens;
bool comp(string a, string b) {
    return (dictionary[a] - dictionary[b]) < 0 ? true : false;
}

int main() {
    string buff;
    int index = 0;
    while (cin >> buff && buff != "#") {
        dictionary[buff] = ++index;
        size_t length = buff.size();
        lens.insert(length);
    }
    while (cin >> buff && buff != "#") {
        size_t length = buff.size();
        list<string> queue;
        if (lens.find(length) != lens.end()) {
            if (dictionary.find(buff) != dictionary.end()) {
                cout << buff << " is correct" << endl;
                continue;
            }
            for (char c = 'a'; c <= 'z'; ++c) {
                for (int i = 0; i < buff.size(); ++i) {
                    string temp = buff;
                    temp.replace(i, 1, 1, c);
                    if (dictionary.find(temp) != dictionary.end()) {
                        queue.push_back(temp);
                    }
                }
            }
        }
        if (lens.find(length - 1) != lens.end()) {
            for (int i = 0; i < buff.size(); ++i) {
                string temp = buff;
                temp.erase(i, 1);
                if (dictionary.find(temp) != dictionary.end()) {
                    queue.push_back(temp);
                }
            }
        }
        if (lens.find(length + 1) != lens.end()) {
            for (char c = 'a'; c <= 'z'; ++c) {
                for (int i = 0; i <= buff.size(); ++i) {
                    string temp = buff;
                    temp.insert(i, 1, c);
                    if (dictionary.find(temp) != dictionary.end()) {
                        queue.push_back(temp);
                    }
                }
            }
        }
        queue.unique();
        queue.sort(comp);
        cout << buff << ":";
        for (list<string>::iterator it = queue.begin(); it != queue.end(); ++it) {
            cout << " " << *it;
        }
        cout << endl;
    }
    return 0;
}
```

- 普通版本 （待完善，好心人请帮忙发送到20270228@tsinglan.cn）