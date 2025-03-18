class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int m = 0 , sub = 0 , l = 0 , r = 0;
        while(r < nums.size()){
            
            while((sub & nums[r]) != 0){
                sub ^= nums[l];
                l += 1;
            }
            sub |= nums[r];
            m = max(m , r-l+1);
            r++;
        }
        return m;
    }
};