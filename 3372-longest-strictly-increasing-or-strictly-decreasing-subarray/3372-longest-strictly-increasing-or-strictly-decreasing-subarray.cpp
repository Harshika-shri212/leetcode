class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int maxi = 1;

       int m = 1;
       for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) m+=1;
            else{
                maxi = max(maxi , m);
                m = 1;
            }
       }

       int l = 1;
       for(int i = 1; i<nums.size(); i++){
            if(nums[i] < nums[i-1]) l+=1;
            else{
                maxi = max(maxi , l);
                l = 1;
            }
       }

    return max(maxi , max( m , l));
    }
};