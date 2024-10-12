#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
int n, k;
int Merge[maxn][maxn], zt[maxn][maxn], dp[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string ch;
        cin>>ch;
        Merge[ch[1]-'A'+1][ch[2]-'A'+1]|=1<<(ch[0]-'A'+1);
    }   
    cin>>k;
    while(k--){
        memset(zt, 0, sizeof(zt));
        memset(dp, 0x3f, sizeof(dp));
        string now;
        cin>>now;
        int stlen=now.size();
        for(int i=0;i<stlen;i++){
            if (now[i] == 'S')
                dp[i+1][i+1]=1;
            zt[i+1][i+1]|=(1<<(now[i]-'A'+1));
        }
        for(int len=0;len<stlen;len++){
            for(int l=1;l+len<=stlen;l++){
                int r=l+len;
                for(int k=l;k<r;k++){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                    for(int x=1;x<=26;x++){
                        for(int y=1;y<=26;y++){
                            if((zt[l][k] & (1<<(x))) && (zt[k+1][r] & (1<<(y))))
                                zt[l][r] |= Merge[x][y];
                        }
                    }
                }
                if(zt[l][r] & (1 << ('S' - 'A' + 1)))
                    dp[l][r] = 1;
            }
        }
        if(dp[1][stlen] >= 0x3f3f3f3f)
            cout<<"NIE"<<endl;
        else
            cout<<dp[1][stlen]<<endl;
    }
}

/*
in:
6
SAB
SBC
SAA
ACA
BCC
CBC
3
ABBCAAABCA
CCC
BA

out:
3
1
NIE
*/