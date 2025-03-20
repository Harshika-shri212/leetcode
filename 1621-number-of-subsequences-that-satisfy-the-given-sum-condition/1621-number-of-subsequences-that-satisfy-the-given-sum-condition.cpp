class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1000000007;
        sort(nums.begin() , nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int c = 0;
        vector<int>powers(nums.size());
        powers[0] = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            powers[i] = (powers[i - 1] * 2 ) % mod;
        }
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                c += powers[r - l];
                c %= mod;
                l += 1;
            }
            else r -= 1;
        }
        return c;
    }
};