```cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,a[1000001],maxn=-1,minn=999999999;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(a[i]>maxn && a[i]!=-1 && (a[i-1]==-1 || a[i+1]==-1)) maxn=a[i];
            if(a[i]<minn && a[i]!=-1 && (a[i-1]==-1 || a[i+1]==-1)) minn=a[i];
        }
        if(maxn==-1 && minn==999999999){
            maxn=0;
            minn=0;
            cout<<"0 0"<<endl;
            continue;
        }
        int k=(minn+maxn)>>1,ans=-1;
        for(int i=1;i<=n;i++){
            if(a[i]==-1) a[i]=k;
            if(i!=1)ans=max(ans,abs(a[i]-a[i-1]));
        }
        cout<<ans<<" "<<k<<"\n";
    }
}
```