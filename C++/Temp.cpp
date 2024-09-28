#include <bits/stdc++.h>
using namespace std;

vector<int> stone_heap;
int n,temp;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        stone_heap.push_back(temp);
    }
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        
    }
    cout<<dp[n-1];
}

/**
 * 4
 * 4 5 9 4
 * 
 * 4 5 -> sum = 9
 * 9 4 -> sum = 13
 * 13 9 -> sum= 21
 * 
 */