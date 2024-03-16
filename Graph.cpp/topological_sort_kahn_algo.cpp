#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
int v;
void add_edge(int a,int b,bool bi_dir=false){
    graph[a].push_back(b);
    if(bi_dir){
        graph[b].push_back(a);
    }
}
// dipendency vale problem ko solve karne ke kam aata h
void topoBFS(){
    //kahn algo
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbor : graph[i]){
            //i-->neighbor
            indegree[neighbor]++;
        }
    }
    for(int i=0;i<v;i++){
        cout<<indegree[i]<<" ";
    }
    cout<<endl;
    queue<int>q;
    vector<int>vis;//unordered_set bhi le sakte h
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
            vis.push_back(i);
        }
    }
   
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto neighbor : graph[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
                vis.push_back(neighbor);
            }
        }
    }
}
int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topoBFS();
}