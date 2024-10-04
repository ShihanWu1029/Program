#include<iostream>
using namespace std;

const int N = 250;
int dp[N][N];

int main() {
    int n,ans = -1;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d", dp[i] + i);
        ans = max(ans, dp[i][i]);
    }

    for(int len=2;len<=n; len++) 
        for(int l=1;l+len-1<=n;l++) {
            int r
            =l+len-1;
            for(int k = l; k < r; k++) 
                if(dp[l][k] == dp[k+1][r] && dp[l][k]) {
                    dp[l][r] = max(dp[l][r], dp[l][k]+1);
                    ans = max(ans,dp[l][r]);
                }
        }

    printf("%d\n", ans);		
    return 0;
}