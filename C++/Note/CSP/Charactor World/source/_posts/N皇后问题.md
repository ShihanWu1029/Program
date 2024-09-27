---
title: N皇后问题
date: 2023-08-14 11:16:32
tags: CSP-S
categories: 题解
---

## AC代码

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int g[11][11];
int ans=0;

bool check(int x,int y,int n){
	for(int i=1;i<=n;i++) if(g[i][y]==1) return true;
	for(int i=x-1,j=y+1;i>=1 && j<=n ;i--,j++) if(g[i][j]==1) return true;
	for(int i=x-1,j=y-1;i>=1 && j>=1 ;i--,j--) if(g[i][j]==1) return true;
	for(int i=x+1,j=y-1;i<=n && j<=n ;i++,j++) if(g[i][j]==1) return true;
	for(int i=x+1,j=y-1;i<=n && j>=1 ;i++,j--) if(g[i][j]==1) return true;
	return false;
}

void nqueen(int h,int n){
	if(h==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!check(h,i,n)){
			g[h][i]=1;
			nqueen(h+1,n);
			g[h][i]=0;
		}
	}
}

int main(){
	int n;
	cin>>n;
	while(n!=0){
		ans=0;
		memset(g,0,sizeof(g));
		nqueen(1,n);
		cout<<ans<<"\n";
		cin>>n;	
	}
}
```
