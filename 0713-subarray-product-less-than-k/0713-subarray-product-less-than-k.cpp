class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; 
        
        int l = 0, r = 0, c = 0, prod = 1;

        while (r < nums.size()) {
            prod *= nums[r];

            while (prod >= k && l <= r) { 
                prod /= nums[l];
                l++;
            }

            int ind = r - l + 1;
            c += ind; 
            r++;
        }
        return c;
    }
};
