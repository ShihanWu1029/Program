```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,a[100001],b[100001],c[100001],d[100001],ans=0;
int sum1[4010*4010],sum2[4010*4010],cnt=0;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum1[cnt]=a[i]+b[j];
            sum2[cnt]=c[i]+d[j];
            cnt++;
        }
    }
    sort(sum2,sum2+cnt);
    for(int i=0;i<cnt;i++){
        int f=sum1[i] * (-1);
        int *l = lower_bound(sum2,sum2+cnt,f);
        int *r = upper_bound(sum2,sum2+cnt,f);
        ans+=r-l;
    }
    cout<<ans<<endl;
}
```