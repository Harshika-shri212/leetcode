class Solution {
public:

    int solve(int i, int j, int m, vector<vector<int>> & dp, vector<vector<int>> & triangle){
        if(i==m-1) return triangle[i][j];
        else if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = triangle[i][j] + fmin(solve(i+1,j,m,dp,triangle), solve(i+1,j+1,m,dp,triangle));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp (m,vector<int>(m,-1));
        return solve(0,0,m,dp,triangle);
    }
};