// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V+1);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //Min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto node: adj[u]){
                int v=node.first;
                int w=node.second;
                if(d+w<dist[v]){
                     dist[v]=d+w;
                     pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};