#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
unordered_set<int>vis;
void add_Edge(int a, int b, bool bi_dir = true)
{
    graph[a].push_back(b);
    if (bi_dir)
        graph[b].push_back(a);
}
  void dfs( int node ){
     vis.insert(node);
     for(auto neighbor : graph[node]){
        if(!vis.count(neighbor)){
            dfs(neighbor);
        }
     }
  }
int conected_component(){
    int count=0;
    for(int i=0;i<graph.size();i++){
        if(vis.count(i)==0){
            count++;
            dfs(i);
        }
    }
    return count;
}

int main()
{

    int v, e;
    cin >> v >> e;
    graph.resize(v, list<int>());

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        add_Edge(a, b, true);
    }

    cout<<conected_component();
}