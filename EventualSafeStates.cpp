// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> revAdj(V);
        vector<int> indegree(V+1,0);
        for(int i=0;i<V;i++){
            int n=adj[i].size();
            for(int j=0;j<n;j++){
                revAdj[adj[i][j]].push_back(i);
                indegree[i]++;

            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbor: revAdj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)
                q.push(neighbor);
            }
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
