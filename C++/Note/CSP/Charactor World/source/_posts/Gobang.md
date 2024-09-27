---
title: Gobang
date: 2023-08-11 18:57:34
tags: CSP-S
categories: 题解
---

## AC代码

```cpp
#include <iostream>
using namespace std;

char board[9][9];


bool dogBang() {
    // 检查行
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (board[row][col] == '1' &&
                board[row][col+1] == '1' &&
                board[row][col+2] == '1' &&
                board[row][col+3] == '1' &&
                board[row][col+4] == '1') {
                return true;
            }
        }
    }

    // 检查列
    for (int col = 0; col < 9; ++col) {
        for (int row = 0; row < 5; ++row) {
            if (board[row][col] == '1' &&
                board[row+1][col] == '1' &&
                board[row+2][col] == '1' &&
                board[row+3][col] == '1' &&
                board[row+4][col] == '1') {
                return true;
            }
        }
    }

    // 检查主对角线
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (board[row][col] == '1' &&
                board[row+1][col+1] == '1' &&
                board[row+2][col+2] == '1' &&
                board[row+3][col+3] == '1' &&
                board[row+4][col+4] == '1') {
                return true;
            }
        }
    }

    // 检查副对角线
    for (int row = 0; row < 5; ++row) {
        for (int col = 4; col < 9; ++col) {
            if (board[row][col] == '1' &&
                board[row+1][col-1] == '1' &&
                board[row+2][col-2] == '1' &&
                board[row+3][col-3] == '1' &&
                board[row+4][col-4] == '1') {
                return true;
            }
        }
    }

    return false;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin>>board[i][j];
			}
		}
		bool flag=false;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				if(board[i][j]=='.'){
					board[i][j]='1';
					flag=dogBang();
					board[i][j]='.';
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
}
```
