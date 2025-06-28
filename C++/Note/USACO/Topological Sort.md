# Topological Sort 拓扑排序

## 概念

比如，如果用一个DAG图来表示一个工程，其中每个顶点表示工程中的一个任务，用有向边表示在做任务 B 之前必须先完成任务 A。故在这个工程中，任意两个任务要么具有确定的先后关系，要么是没有关系，绝对不存在互相矛盾的关系（即环路）。

## DAG

有向无环图：

- 全部为有向边

- 不存在环

## 算法

### Kahn算法(BFS)

O(N+M) 点数和边数

使用最广泛，最方便

#### 原理

核心思想：做完一件事就打勾

步骤：

- 1.找到入度为0 的顶点找到并记录到队列或者栈中；
- 2.移除找到的入度为0的顶点和对应的以该顶点为起点的边，并将被移除的顶点加入到list集合中，同时移除的顶点作为起点的边的终点的如度减去1；继续循环1的步骤，直至队列或者栈为空。
- 3.此时list集合中的顶点的顺序输出就是拓扑排序的结果；如果list集合的元素数量少于顶点数量则说明该有向图存在环。

#### 代码

```cpp
const int max_size=5001;
vector<int> g[max_size];
int in_degree[max_size],real_size;
bool vis[max_size];

void push(int u,int v){
	g[u].push_back(v);
	in_degree[v]++;
	real_size=max(real_size,max(u,v));
}

vector<int> topological_sort(){
	vector<int> ret;
	queue<int> q;
	for(int i=0;i<real_size;i++)
		if(in_degree[i]==0)
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ret.push_back(u);
		for(auto i : g[u]){
			if(--in_degree[i] == 0){
				q.push(i);
			}
		}
	}
	return ret;
}
```

### Corman-Tarjan算法(DFS)

O(N+M) 实现较为复杂

### 基于并行随机存取机的算法

十分复杂，不讨论