class Solution {
public:
    void pass_through(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component) {
        vis[i] = 1;
        component.push_back(i);
        
        for (int j = 0; j < adj[i].size(); j++) {
            if (!vis[adj[i][j]]) {
                pass_through(adj[i][j], adj, vis, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> component;
                pass_through(i, adj, vis, component);

                bool isComplete = true;
                int size = component.size();
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) count++;
            }
        }

        return count;
    }
};
