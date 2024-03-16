#include<bits/stdc++.h>
#define ll long long 
using  namespace std;

int find_parent(int x , vector<int>&parent){
    if(x== parent[x])return x;
    return parent[x] = find_parent(parent[x] , parent);
}

void Union(int a, int b , vector<int>&parent , vector<int>&rank){
    a  = find_parent(a , parent);
    b = find_parent(b , parent);

    if(a == b )return ;//same component me h 

    if(rank[a] >= rank[b]){
        parent[b] = a;
        rank[a]++;
    }
    else {
        parent[a] = b;
        parent[b]++;
    }
}

struct Edge{
  int src;
  int dest;
  int wt;
};

bool cmp(Edge e1 , Edge e2){
    return e1.wt < e2.wt;
}

ll Kruskals(vector<Edge>&input , int n ,int e){
    sort(input.begin(),input.end() , cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    int EdgeCount = 0 ;//n-1 se kam hoga
    ll ans =0;
    int i=0;//input.size() se kam hoga
    while (EdgeCount < n-1 and i<input.size()){
        Edge curr = input[i];//input is sorted so we will get min wt edge
        int srcPar = find_parent(curr.src ,parent);
        int dstPar = find_parent(curr.dest , parent);

        if(srcPar != dstPar){
            //include edge as this will note make cycle
            Union(srcPar , dstPar , parent , rank);
            ans+=curr.wt;
            EdgeCount++;
        }
        i++; //doesnt metter u picked the last edge or note , we still need to go to the next edge
    }
    
    return ans;
}
int main(){

int n,e;
cin>>n>>e;

vector<Edge>v(e);

for(int i=0;i<e;i++){
    cin>>v[i].src>>v[i].dest>>v[i].wt;
}

cout<<Kruskals(v , n , e);
}
