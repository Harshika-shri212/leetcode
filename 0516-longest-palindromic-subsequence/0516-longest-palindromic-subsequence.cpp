class Solution {
public:

    int solve(int i, int j, string & s, vector<vector<int>> & dp){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return 2 + solve(i+1 , j-1 , s, dp);
        else return dp[i][j] = fmax( solve(i,j-1,s,dp) , solve(i+1,j,s,dp) );
    }

    int longestPalindromeSubseq(string s) {
        int i = 0;
        int j = s.size() - 1;
        vector<vector<int>> dp (s.size() , vector<int> (s.size() , -1));
        return solve(i , j, s, dp);
    }
};