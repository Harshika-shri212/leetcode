class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int tot = ( n * (n + 1) ) / 2;
        int nums_tot = accumulate(nums.begin() , nums.end() , 0);
        return tot - nums_tot;
    }
};