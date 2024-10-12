# Class 6

## Grid

### 题意

h*w的矩阵
从左上(1,1) -> 右下(h,w)
每次向右或向下
有些格子不能走
求方案数量

### 解

往右要走w-1步
左要走h-1步

![](../../../Resource/HJJ%20Class%206%20-1.png)

```cpp
#include <bits/stdc++.h>
#define ll long long
#define mode 1000000007
#define maxn 200000
using namespace std;
ll inv[200005];
ll mul[200005];
void init(){
    inv[1]=1;
    inv[0]=1;
    mul[0]=1;
    for(int i=2;i<=maxn;i++){
      inv[i]=(mode-mode/i)*inv[mode%i]%mode;
    }
    for(int i=1;i<=maxn;i++){
        inv[i]*=inv[i-1];
        inv[i]%=mode;
        mul[i]=mul[i-1]*i;
        mul[i]%=mode;
    }
}
int n,m,k;
struct Bad{
    int x,y;
}p[3005];
ll dp[3005];
bool cmp(Bad a,Bad b){
    if(a.x==b.x)
        {
        return a.y<b.y;
        }
    return a.x<b.x;
}
ll C(int x,int y){
    return mul[x]%mode*inv[y]%mode*inv[x-y]%mode;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i=1;i<=k;i++)
        {
        scanf("%d%d",&p[i].x,&p[i].y);
        }
        k++;
        p[k].x=n;
        p[k].y=m;
    sort(p+1,p+k+1,cmp);
    for(int i=1;i<=k;i++){
        dp[i]=C(p[i].x+p[i].y,p[i].x);
        for(int j=1;j<i;j++){
            if(p[j].x<=p[i].x&&p[j].y<=p[i].y){
                dp[i]-=dp[j]*C(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x)%mode;
            }
        }
        dp[i]=(dp[i]%mode+mode)%mode;
    }
    cout<<dp[k];
}
```