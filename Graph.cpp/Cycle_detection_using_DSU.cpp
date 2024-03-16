
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x], parent);
}

bool Union(int a, int b, vector<int> &parent, vector<int> &rank)
{
    a = find(a, parent);
    b = find(b, parent);
     if(a==b)return true;
    if (rank[a] <= rank[b])
    {
        parent[a] = b; // parent a ko b me add kar rahe h
        rank[b]++;
    }
    else
    {
        parent[b] = a;
        rank[a]++;
    }
    return false;
}
int main()
{         
  ///  tc : o(log*n)
    int n, m; //
    cin >> n >> m;
    // n->no. of ele
    // m->no. of queries
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }

    while (m--)
    {
        int x,y;
        cin>>x>>y;
        bool b = Union(x,y ,parent , rank );
        if(b==true)cout<<"Cycle detect";
       
    }
}