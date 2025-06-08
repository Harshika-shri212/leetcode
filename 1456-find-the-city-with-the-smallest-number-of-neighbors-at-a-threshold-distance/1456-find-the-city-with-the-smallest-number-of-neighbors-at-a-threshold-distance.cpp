class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(int i = 0 ; i < n ; i++){
            adj[i][i] = 0;
        }
        for(auto edge : edges){
            int i = edge[0];
            int j = edge[1];
            int wt = edge[2];
            adj[i][j] = wt;
            adj[j][i] = wt;
        }

        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(i != k || j != k || i != j){
                        if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                            adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
                        }
                    }
                }
            }
        }

        int city = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            int c = 0;
            for(int j = 0 ; j < n ; j++){
                if(adj[i][j] <= distanceThreshold) c+=1;
            }
            if(c < mini){
                city = i;
                mini = c;
            }
            else if(c == mini){
                city = max(city , i);
            }
        }
        return city;
    }
};