// We can use bellman ford algorithm to find the shortest path in a graph with negative weights
// Also we can use to detect negative weight cycles in the graph 
// We relax all edges |V|-1 times but if further relaxation is possible,
// then there is a negative weight cycle
// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto itr: edges){
                int u=itr[0];
                int v=itr[1];
                int w=itr[2];
                if(dist[u]!=1e8&&dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
            }
        }
        for(auto itr: edges){
                int u=itr[0];
                int v=itr[1];
                int w=itr[2];
                if(dist[u]!=1e8&&dist[u]+w<dist[v])
                return {-1};
            }
        return dist;
    }
};
// TC: O(V*E)   SC: O(V)