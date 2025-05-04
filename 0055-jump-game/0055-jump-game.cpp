class Solution {
public:
    bool traverse(int indi ,vector<int> &nums ,vector<int> &dp ){
        if(indi == nums.size()-1) return true;
        if (dp[indi] != -1) return dp[indi];
        for (int i = 1; i<=nums[indi] ; i++){
            if (traverse(indi+i , nums , dp)){
                return true;
            }
        }
        return dp[indi] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return traverse(0 , nums , dp);
    }
};