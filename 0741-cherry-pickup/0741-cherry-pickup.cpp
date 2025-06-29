class Solution {
public:

    vector<vector<vector<int>>> dp;
    int n;

    int helper(int x1, int y1, int x2, vector<vector<int>>& grid) {
        int y2 = x1 + y1 - x2; // since steps = x1 + y1 = x2 + y2

        if (x1 >= n || y1 >= n || x2 >= n || y2 >= n ||
            grid[x1][y1] == -1 || grid[x2][y2] == -1) return -1e9;

        if (x1 == n - 1 && y1 == n - 1) return grid[x1][y1];

        if (dp[x1][y1][x2] != -1) return dp[x1][y1][x2];

        int cherries = 0;
        if (x1 == x2 && y1 == y2)
            cherries = grid[x1][y1];
        else
            cherries = grid[x1][y1] + grid[x2][y2];

        int best = max({
            helper(x1 + 1, y1, x2 + 1, grid),
            helper(x1, y1 + 1, x2, grid),
            helper(x1 + 1, y1, x2, grid),
            helper(x1, y1 + 1, x2 + 1, grid)
        });

        cherries += best;

        return dp[x1][y1][x2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int res = helper(0, 0, 0, grid);
        return max(0, res);
    }
};