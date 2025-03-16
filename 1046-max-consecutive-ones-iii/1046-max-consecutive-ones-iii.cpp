class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zero_count = 0, m = 0;
        
        while (r < nums.size()) {
            if (nums[r] == 0) zero_count++;  
            
            while (zero_count > k) { 
                if (nums[l] == 0) zero_count--;
                l++;
            }

            m = max(m, r - l + 1);  
            r++;
        }
        return m;
    }
};
