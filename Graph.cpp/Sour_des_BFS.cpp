
#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<int>>graph;
 void add_edge(int a,int b,bool bi_dir = true){
    graph[a].push_back(b);
    if(bi_dir){
        graph[b].push_back(a);
    }
 }
 int step=0;
 void bfs_source(int sor){
    queue<pair<int,int>>q1;
    vector<int>vis={0};
    q1.push({sor,0});
    vis[sor]=1;
    while(!q1.empty()){
        int node = q1.front().first;
         int lv  = q1.front().second;
        q1.pop();
        step++;
        for(auto neighbor : graph[node]){
            if(!vis[neighbor]){
                q1.push({neighbor,lv+1});
                vis[neighbor] = 1;
            }
        }
    }
   
 }
int main(){
cin>>v;
int e;
cin>>e;
graph.resize(v, list<int>());
while(e--){
    int x,y;
    cin>>x>>y;
    add_edge(x,y,true);
}
int cn=0;
for(int i=0;i<v;i++){
    bfs_source(i);
    cn++;
}
  cout<<cn;
}