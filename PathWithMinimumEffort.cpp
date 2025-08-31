#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<vector<int>> dist(rows, vector<int>(columns, INT_MAX));
        priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;
            
            if(row == rows - 1 && col == columns - 1) 
                return diff;
            
            for(int i = 0; i < 4; i++) {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                
                if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < columns) {
                    int newdiff = max(abs(heights[newrow][newcol] - heights[row][col]), diff);
                    if(newdiff < dist[newrow][newcol]) {
                        dist[newrow][newcol] = newdiff;
                        pq.push({newdiff, {newrow, newcol}});
                    }
                }
            }
        }
        
        return 0; 
    }
};
