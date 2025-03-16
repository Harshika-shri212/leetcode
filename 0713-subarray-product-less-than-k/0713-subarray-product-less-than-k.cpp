class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            int prod = nums[i];
            if(prod < k) c += 1;
            else continue;
            for(int j = i + 1 ; j < nums.size() ; j++){
                prod *= nums[j];
                if(prod < k) c += 1;
                else break;
            }
        }
        return c;
    }
};