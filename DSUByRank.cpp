#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent, rank;
    public:
    int n;
    DisjointSet(int n){
        this->n=n;
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int par_u=findParent(u);
        int par_v=findParent(v);
        if(par_u==par_v) return;
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
    }
};
int main(){
    DisjointSet ds(5);
    ds.unionByRank(0, 1);
    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);
    cout << ds.findParent(0) << endl;  
    cout << ds.findParent(3) << endl;  
    return 0;
}