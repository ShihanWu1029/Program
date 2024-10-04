# Digital DP

## Intro

If there are numbers from 0 ~ 9999999999999..., find how many digital sum of numbers in the range are 130.

Obviously, you can't go threw all numbers.

So, how to solve?

### Try

Change the condition to numbers from 0 ~ 999, and the digital sum required is 25.

We can let dp[i][j] refer to the number of numbers that the $i^{th}$ digit we have used and the sum is j.

So we only need to find dp[3][25].

Need to find dp[2][1~18] then dp[1][1~9].

Work out the table...

$$
dp[3][25] = \sum_{i=25-9=16}^{25} dp[1][i]
$$

$$
dp[2][16] = \sum_{i=16-9=7}^{16} dp[1][i]
$$


Program is like below:

```cpp
#include <iostream>
using namespace std;

int dp[3][26];
int main(){
    for(int i=0;i<=9;i++) dp[0][i]=1;
    for(int i=1;i<=2;i++){
        for(int j=0;j<=25;j++){
            //Not This hhh dp[i][j] = dp[i-1][j] + dp[i][j-1];
            for(int k=0;k<=9;k++){
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    cout<<dp[2][25];
}
```

### But..

What if the number is from 0~500?

We find that in some places we can't fill in 9 or else.

