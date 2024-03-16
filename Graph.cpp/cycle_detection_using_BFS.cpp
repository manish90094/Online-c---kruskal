#include <bits/stdc++.h>
using namespace std;
int v;
vector<list<int>> graph;
void add_Edge(int a, int b, bool bi_dir = true)
{
    graph[a].push_back(b);
    if (bi_dir)
        graph[b].push_back(a);
}
bool bfs(int sour)
{
vector<int>vis;
vector<int>par(v,-1);
queue<int>q;
q.push(sour);
vis.push_back(sour);
while(!q.empty()){
   int node = q.front();
   q.pop();
   for(auto neighbor : graph[node]){
    if(vis[neighbor] and par[node] != neighbor)return true;
    if(!vis[neighbor]){
        vis.push_back(neighbor);
        par[neighbor] = node;
        q.push(neighbor);
    }
   }
}
}
bool has_Cycle()
{
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            bool res = bfs(i);
            if (res == true)
                return true;
        }
    }
    return false;
}
int main()
{

    cin >> v;
    int e;
    cin >> e;
    graph.resize(v, list<int>());

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        add_Edge(a, b, true);
    }

    bool b = has_Cycle();
    cout << "Cycle detect" << b << " ";
}