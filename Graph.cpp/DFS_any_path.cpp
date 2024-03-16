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
  bool dfs(int curr,int end  ){
    if(curr==end)return true;
      vis.insert(curr);
      for(auto neighbour : graph[curr]){
        if(vis.count(neighbour)){
            bool result = dfs(neighbour,end);
            if(result)return true;
        }
      }
      return false;
  }

bool any_path(int start , int end){
    return dfs(start,end);
}
void display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << "->";

        for (auto it : graph[i])
        {
            cout << it << ",";
        }
        cout << endl;
    }
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

    int x,y;
    cin>>x>>y;
    cout<<any_path(x,y);
}