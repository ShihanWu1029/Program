#include<iostream>
#include<algorithm>
using namespace std;
long long n,t,a[100010],c[100010],f;
int main(){
    cin>>n>>t;
    for(int i=1;i<=n;++i){
        int x,y;
        cin>>x>>y;
        a[i]=x+t*y;
    }
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        if(c[f]<=a[i]){
            ++f;
            c[f]=a[i];
        }
        else
            *upper_bound(c+1,c+f+1,a[i])=a[i];
    }
    cout<<f<<endl;
    return 0;
}