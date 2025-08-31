// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        const int INF = 1e9;
        const int mod = 100000;
        queue<pair<int,int>> q;
        vector<int> dist(100000,INF);
        dist[start]=0;
        q.push({0,start});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.second;
            int steps=it.first;
            for(auto child: arr){
                int childNode=(child*node)%mod;
                if(steps+1<dist[childNode]){
                    dist[childNode]=steps+1;
                    q.push({steps+1,childNode});
                }
            }
        }
        if(dist[end]==INF) return -1;
        else return dist[end];
    }
};
