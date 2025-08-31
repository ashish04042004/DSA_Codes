#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        int sz=roads.size();
        for(int i=0;i<sz;i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0LL);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        dist[0]=0LL;
        ways[0]=1LL;
        pq.push({0,0});
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            ll u=node.second;
            ll d=node.first;
            for(auto child: adj[u]){
                ll v=child.first;
                ll w=child.second;
                if(d+w<dist[v]){
                    dist[v]=d+w;
                    ways[v]=ways[u]%mod;
                    pq.push({dist[v],v});
                }
                else if(d+w==dist[v]){
                    ways[v]=((ways[v]%mod)+(ways[u]%mod))%mod;
                }
            }
        }
        return (int)(ways[n-1]%mod);
    }
};