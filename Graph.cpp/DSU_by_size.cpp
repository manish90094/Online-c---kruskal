#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int findParent(int i, int parent[])
// function to find the connected component that the ith node belongs to
{
    if (parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}
void unionNodes(int a, int b, int parent[], int size[])
// to merge the connected components of nodes a and b
{
    int parent_a = findParent(a, parent), parent_b = findParent(b, parent);
    if (parent_a == parent_b)
        return;
    if (size[parent_a] >= size[parent_b]) // the larger connected component eats up the smaller one
    {
        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;
    }
    else
    {
        size[parent_b] += size[parent_a];
        parent[parent_a] = parent_b;
    }
    return;
}