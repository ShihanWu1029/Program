#include <bits/stdc++.h>
using namespace std;

map<char,int> q;
int pk[4][4];
char x;
int n,k,a[100010],f[100010][21][4];

int main(){
	q['H']=1; q['S']=2; q['P']=3;
    pk[1][2]=1; pk[2][3]=1; pk[3][1]=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=q[x];
	} 
	for(int i=1;i<=n;i++)
        for(int j=0;j<=min(k,i);j++)
            for(int k=1;k<=3;k++){
                int temp=pk[k][a[i]];
                f[i][j][k]=max(f[i-1][j][k]+temp,f[i][j][k]);
                for(int l=1;l<=3;l++){
                    if(l!=k&&j)
                    f[i][j][k]=max(f[i][j][k],f[i-1][j-1][l]+temp);
                }
	    }
	int ans=0;
	for(int i=1;i<=3;i++)  ans=max(f[n][k][i],ans);
	cout<<ans;
	return 0;
}