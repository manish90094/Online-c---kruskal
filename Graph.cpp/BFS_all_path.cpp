#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 int v;
 vector<list<int>> graph;
 unordered_set<int> vis;
void add_Edge(int a, int b, bool bi_dir = true)
{
    graph[a].push_back(b);
    if (bi_dir)
        graph[b].push_back(a);
}

void bfs(int sour, vector<int> &dis)
{
    queue<int>q;
    vis.clear();
    dis.resize(v,INT_MAX);
    q.push(sour);
    vis.insert(sour);
    dis[sour] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto neighbour : graph[curr]){
            if (!vis.count(neighbour))
            {
                q.push(neighbour);
                vis.insert(neighbour);
                dis[neighbour] = dis[curr] + 1;
                q.pop();
            }
        }
    }

}

int main()
{
    vis.clear();
    int  e;
    cin >> v >> e;
    graph.resize(v, list<int>());
    vector<int>dis;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        add_Edge(a, b ,true);
    }

    int x;
    cin >> x;
    bfs(x , dis);

    for(int i=0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }
}