class Solution {
public:

    int binary(vector<tuple<int , int , int >>& jobs , int ind){
        int l = ind + 1;
        int n = jobs.size();
        int r = n - 1;

        int ans = n;

        while(l <= r){
            int mid = (l + r) / 2;
            if(get<1>(jobs[ind]) <= get<0>(jobs[mid])){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }

    int solve(vector<tuple<int , int , int >> &jobs , vector<int>& dp , int ind){
        int n = jobs.size();
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int res1 = solve(jobs , dp , ind + 1);

        int nxt = binary(jobs , ind);
        int res2 = solve(jobs , dp , nxt) + get<2>(jobs[ind]);

        return dp[ind] = max(res1 , res2);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<tuple<int , int , int >>jobs(n);

        for(int i = 0 ; i < n ; i++){
            jobs[i] = {startTime[i] , endTime[i] , profit[i]};
        }

        sort(jobs.begin() , jobs.end());

        vector<int>dp(n , -1);

        return solve(jobs , dp , 0);
    }
};