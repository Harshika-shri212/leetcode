class Solution {
public:

    int fn(vector<vector<int>>& grid , vector<vector<vector<int>>>& dp , int m , int n , int i , int j1 , int j2){
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) return -1e8;
        if(i == m-1){
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
            for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                int val;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                val += fn(grid , dp , m , n , i+1 , j1+dj1 , j2+dj2);
                maxi = max(maxi , val);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>>dp(m , vector<vector<int>>(n , vector<int>(n , -1)));

        return fn(grid , dp , m , n , 0 , 0 , n-1);
    }
};