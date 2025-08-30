class Solution {
  public:
  
    void dfs(int node,vector<vector<int>> &adj,stack<int> &st,vector<bool> &vis){
        int V=adj.size();
        vis[node]=true;
        for(auto neighbor: adj[node]){
            if(!vis[neighbor])
            dfs(neighbor,adj,st,vis);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V+1,false);
        vector<vector<int>> adj(V+1);
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,adj,st,vis);
        }
        vector<int> ans;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            ans.push_back(node);
        }
        return ans;
    }
};