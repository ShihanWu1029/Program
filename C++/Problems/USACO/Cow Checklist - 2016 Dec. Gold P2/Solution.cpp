#include<bits/stdc++.h>
using namespace std;

int n,m;
long long f[1009][1009][2],dis1[1009],dis3[1009],dis2[1009][1009];
struct node{
    int x,y;
}H[1009],G[1009];

int main(){
    memset(f,0x7f,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>H[i].x>>H[i].y;
    for(int i=1;i<=m;i++)
        cin>>G[i].x>>G[i].y;
    for(int i=1;i<n;i++){
        dis1[i]=pow(H[i].x-H[i+1].x,2)+pow(H[i].y-H[i+1].y,2);
    }
    for(int i=1;i<m;i++){
        dis3[i]=pow(G[i].x-G[i+1].x,2)+pow(G[i].y-G[i+1].y,2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis2[i][j]=pow(H[i].x-G[j].x,2)+pow(H[i].y-G[j].y,2);

        }
    }
    f[1][0][0]=0;//从题目可以看出农夫约翰最开始位于H序列的第一个点，所以第一维数组就是1，G序列一个点也没走所以第二维就是0，题目说农夫约翰在H结束所以第三维就是0
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            f[i][j][0]=min(f[i][j][0],min(f[i-1][j][0]+dis1[i-1],f[i-1][j][1]+dis2[i][j]));
            if(j>0)
                f[i][j][1]=min(f[i][j][1],min(f[i][j-1][1]+dis3[j-1],f[i][j-1][0]+dis2[i][j]));
        }
    }
    cout<<f[n][m][0];
    return 0;
}