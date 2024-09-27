# Floyed Algorithm

It's used to find the shortest path in a undirected weighted graph.

O(n^3):

```cpp
for(int k=1;k<=8;k++){
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            res[i][j]=min(res[i][j],res[i][k]+res[k][j]);
        }
    }
}
```