class Solution {
public:

    int solve(int i, int j, int n1, int n2, string & text1 , string & text2,               vector<vector<int>> & dp){
        if(i >= n1 || j >= n2) return 0;
        if(text1[i] == text2[j]) return dp[i][j] = 1 + solve(i+1,j+1,n1,n2,text1,text2,dp);
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = fmax(solve(i+1,j,n1,n2,text1,text2,dp) , solve(i,j+1,n1,n2,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int> (n2 , -1));
        return solve(0, 0, n1, n2, text1, text2, dp);
    }
};