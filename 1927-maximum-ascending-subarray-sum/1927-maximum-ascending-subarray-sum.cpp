class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int tot = nums[0];
        int m = tot;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) tot+=nums[i];
            else{
                m = max(m , tot);
                tot = nums[i];
            }
        }
        return max(m , tot);
    }
};