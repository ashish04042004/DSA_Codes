class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Mark all characters that appear
        for (auto &w : words) {
            for (char c : w) {
                present[c - 'a'] = true;
            }
        }

        // Build graph edges
        for (int i = 1; i < n; i++) {
            string &w1 = words[i - 1];
            string &w2 = words[i];
            int len = min(w1.size(), w2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found = true;
                    break; // only first mismatch matters
                }
            }

            // Prefix check: if no mismatch found and w1 is longer → invalid
            if (!found && w1.size() > w2.size()) {
                return "";
            }
        }

        // Topological Sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back('a' + node);

            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If some characters couldn't be placed → cycle exists → invalid
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] > 0) {
                return "";
            }
        }

        return ans;
    }
};
