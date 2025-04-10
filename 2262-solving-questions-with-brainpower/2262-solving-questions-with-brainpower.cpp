class Solution {
public:

    long long f(vector<vector<int>>& questions , int ind , int & n , vector<long long> &dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];

        int points = questions[ind][0];
        int skip = questions[ind][1];

        long long choose = points + f(questions ,ind + skip + 1 , n , dp);
        long long skipp = f(questions ,ind + 1 ,n ,dp);
        dp[ind] =  max(choose , skipp);
        return dp[ind];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n,-1);
        return f(questions , 0 , n , dp);
    }
};