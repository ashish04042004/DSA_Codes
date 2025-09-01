class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
            vector<bool> vis(V,false);
            int sum=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,0});
            while(!pq.empty()){
                auto it=pq.top();
                pq.pop();
                int node=it.second;
                int wt=it.first;
                if(vis[node]) continue;
                vis[node]=true;
                sum+=wt;
                for(auto child:adj[node]){
                    int ch=child.first;
                    int w=child.second;
                    if(!vis[ch])
                    pq.push({w,ch});
                }
            }
        
        return sum;
    }
};