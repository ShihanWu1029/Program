# 图论

## 最短路

### BFS

### Dijkstra

#### 优缺点

- 无法处理负边权 （原因：仅一遍贪心）

- 亦无法处理负环

- 效率高

#### 实现

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> graph(5001);

void push(int u,int v,int w){
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
    dijkstra();
	cout<<dis[total_point];
}
```

### Bellman-ford

#### 优缺点

- 无法处理负环。事实上，如果有负环，最短路是不存在的，或者说是负的无限大。

- 效率较低

#### 思想

##### 1

$
dis[0]=0 ,
dis[1...n]=\inf
$

##### 2


$for(i=1;i\le|v|-1;i++)$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$foreach:\{e=(u,v)\} \in E$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$dis[v]=min(dis[v],dis[u]+len[e])$

3

$foreach: \{ e=(u,v) \} \in E$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$if(dis[u]+len[e]<dis[v])$

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;$exit()$ - - - 有负环


#### 其实就是dp的一种。。。

#### 实现

```cpp
int dist[N],backup[N];//dist距离，backup用来存上一次的结果。
struct edge//用来存边
{
    int a;
    int b;
    int w;
}Edge[M];
int Bellman_Ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;//初始化
    for(int i = 0 ; i < k ; i++)//遍历k次
    {
        memcpy(backup,dist,sizeof dist);//存上一次答案。
        for(int j = 0 ; j < m ; j++)
        {
            int a = Edge[j].a, b = Edge[j].b, w = Edge[j].w;
            dist[b] = min(dist[b],backup[a] + w);
        }//遍历所有边
    }
    if(dist[n] > 0x3f3f3f3f/2) return -1;
    /*这里不像Dijkstra写等于正无穷是因为可能有负权边甚至是负环的存在，
    使得“正无穷”在迭代过程中受到一点影响。*/
    return dist[n];
}
```

### Floyd

其实就是跑了n次Bellman-Ford