```cpp
#include <iostream>
using namespace std;

long long up0[1000001],down0[1000001];
long long a[10000001];
int main(){
	long long n,ans1=0,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;++i) {
		if (a[i]<0) {
			down0[i]=up0[i-1]+1;
			up0[i]=down0[i-1];
		}else{
			down0[i]=down0[i-1];
			up0[i]=up0[i-1]+1;
		}
		ans1+=up0[i]; 
		ans2+=down0[i];
	}
	cout<<ans2<<" "<<ans1;
}
```