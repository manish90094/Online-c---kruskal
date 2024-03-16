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
bool dfs(int sour, int par, vector<int> &vis)
{

    vis[sour] = 1;
    for (auto neighbor : graph[sour])
    {
        if (vis[neighbor] and neighbor != par)
        {
            return true;
        }
        if (!vis[neighbor])
        {
            bool res = dfs(neighbor, sour, vis);
            if (res == true)
                return true;
        }
    }
    return false;
}
bool has_Cycle()
{
    vector<int> vis(v,0);
    
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
           bool res = dfs(i, -1, vis);
            if (res == true)
                return true;
        }
    }
    return false;
}
int main()
{

    cin>>v;
    int e;cin>>e;
    graph.resize(v, list<int>());

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        add_Edge(a, b, true);
    }

    bool b = has_Cycle();
    cout <<"Cycle detect"<< b << " ";
}