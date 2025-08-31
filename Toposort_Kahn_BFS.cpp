class Solution {
  public:
  
    vector<int> bfs(vector<vector<int>> &adj,queue<int> &q,vector<bool> &vis,vector<int> &indegree){
       vector<int> ans;
        while(!q.empty()){
        int node=q.front();
        vis[node]=true;
        q.pop();
        for(auto neighbor: adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0)
            q.push(neighbor);
        }
        ans.push_back(node);
        }
        return ans;
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V+1,false);
        vector<vector<int>> adj(V+1);
        vector<int> indegree(V+1,0);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        
        
       
        return bfs(adj,q,vis,indegree);
    }
};