# Graph

## Dijkstra Program

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph(5001);

int push(int u,int v,int w){
	graph[u].push_back(make_pair(v,w));
}

int rt = 0,vis[5001],dis[5001];
priority_queue<int> q;

void dijkstra(){
	for(auto i : dis) i = 0x7fffffff;
	q.push(rt);
	vis[rt] = true;
	dis[rt] = 0;
	while(!q.empty()){
		int npos = q.top();
		q.pop();
		for(auto i : graph[npos]){
			vis[i.first] = true;
			dis[i.first] = min(dis[i.first],dis[npos] + i.second);
			if(!vis[i.first]){
				q.push(i.first);
				vis[i.first] = true;	
			}
		}
	}
}

int main(){
	int total_point,total_sides;
	cin>>total_point>>total_sides;
	for(int i=0;i<total_sides;i++){
		int u,v,w;
		cin>>u>>v>>w;
		push(u,v,w);
	}
	cout<<dis[total_point];
}
```