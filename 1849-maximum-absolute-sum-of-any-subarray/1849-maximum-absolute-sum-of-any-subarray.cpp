class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int cur = 0;
        for(int i : nums){
            cur = cur + i;
            maxi = max(maxi , cur);
            if (cur < 0) cur = 0;
        }

        int mini = INT_MAX;
        int curr = 0;
        for(int i : nums){
            curr = min(curr + i  , i);
            mini = min(mini , curr);
        }

        return max(abs(maxi) , abs(mini));
    }
};