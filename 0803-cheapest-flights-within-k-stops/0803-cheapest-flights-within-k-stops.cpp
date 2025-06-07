class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        for(int i = 0 ; i <= k ; i++){
            vector<int>temp = dist;
            for(auto it : flights){
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if(dist[u] == INT_MAX) continue;
                else{
                    if(dist[u] + wt < temp[v]){
                        temp[v] = dist[u] + wt;
                    }
                }
            }
            dist = temp;
        }
        if(dist[dst] == INT_MAX) return -1;
        else return dist[dst];
    }
};