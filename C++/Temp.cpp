#include <iostream>
using namespace std;

int dp[3][26];
int main(){
    for(int i=0;i<=9;i++) dp[0][i]=1;
    for(int i=1;i<=2;i++){
        for(int j=0;j<=25;j++){
            // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            for(int k=0;k<=9;k++){
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    cout<<dp[2][25];
}