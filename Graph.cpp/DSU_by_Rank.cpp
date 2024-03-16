

// Disjoint set union (DSU)
// USING RANK 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int find_parent(int x,vector<int>&parent){
    if (parent[x] == x)
        return x;

    return parent[x] = find_parent(parent[x], parent);
}

void Union(int a, int b, vector<int> &parent, vector<int> &rank)
{
  a  = find_parent(a,parent);
  b  = find_parent(b,parent );

  if(rank[a] <= rank[b]){
      parent[a] = b;//parent a ko b me add kar rahe h
      rank[b]++;
  }
   else {
       parent[b] = a;
       rank[a]++;
   }

}
int main(){///  tc : o(log*n)
int n,m;//
cin>>n>>m;
//n->no. of ele
//m->no. of queries
vector<int>parent(n+1);
vector<int>rank (n+1,0);

for(int i=0;i<=n;i++){
     parent[i]=i ;
}

while(m--){
    string str;
    cin>>str;
    
    if(str == "union"){
        int x,y;cin>>x>>y;
        Union(x,y,parent,rank);
    }
     else{
        int x;
        cin>>x;
            cout<<find_parent(x,parent);
     }
}

}