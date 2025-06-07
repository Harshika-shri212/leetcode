class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v , wt});
        }

        vector<int>t(n+1,INT_MAX);
        t[0] = -1;
        t[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0,k});

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int node = ele.second;
            int node_dist = ele.first;

            for(auto iter : adj[node]){
                int nextNode = iter.first;
                int cost = iter.second;
                if(t[node] + cost < t[nextNode]){
                    t[nextNode] = t[node] + cost;
                    pq.push({t[node] + cost , nextNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1 ; i <= n ; i++){
            if(t[i] == INT_MAX) return -1;
            else ans = max(ans,t[i]);
        }
        return ans;
    }
};