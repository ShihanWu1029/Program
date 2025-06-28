#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,a,b,res=0;
        bool flag=true;
        cin>>n>>a>>b;
        vector<char> graph[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char t;
                cin>>t;
                graph[i].push_back(t);
            }
        }
        if(a==0 && b==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][j]!='W') res++;
                }
            }
            cout<<res<<endl;
        }else{
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][j]=='B'){
                        int xx=i-b,yy=j-a;
                        if(xx<0 || yy<0 || yy>=n || xx>=n || graph[xx][yy]=='W'){
                            flag=false;
                            break;
                        }
                    }
                }
            }
            for(int i=n-1;i>=b;i--){
                for(int j=n-1;j>=a;j--){
                    if(graph[i][j]=='G'){
                        if(graph[i-b][j-a]=='G'){
                            graph[i][j] = graph[i-b][j-a] = 'W';
                            res++;
                        }
                        if(graph[i-b][j-a]=='B'){
                            graph[i][j] = 'W';
                            graph[i-b][j-a] = 'G';
                            res++;
                        }
                    }
                    if(graph[i][j]=='B'){
                        int xx=i-b,yy=j-a;
                        if(xx<0 || yy<0 || yy>=n || xx>=n || graph[xx][yy]=='W'){
                            flag=false;
                            break;
                        }
                        if(graph[i-b][j-a]=='G'){
                            graph[i-b][j-a] = 'W';
                            graph[i][j] = 'G';
                            res++;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(graph[i][j] == 'G'){
                        res++;
                    }
                }
            }
            cout<<(flag ? res : -1)<<endl;
        }
    }
}
