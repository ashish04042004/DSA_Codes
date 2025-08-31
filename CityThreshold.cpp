class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(auto itr: edges){
            int u=itr[0];
            int v=itr[1];
            int w=itr[2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) matrix[i][j]=0;
                }
            }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
        int index=-1;
        int mini=1e9;
        for(int i=0;i<n;i++){
                int cnt=0;
                for(int j=0;j<n;j++){
                    if(matrix[i][j]<=distanceThreshold){
                        cnt++;
                    }
                }
                if(cnt<=mini){
                    mini=cnt;
                    index=i;
                }
            }
            return index;
    }
};