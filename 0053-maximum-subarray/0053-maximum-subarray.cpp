class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    if (nums.size()==1) return nums[0];
     int max_sum=INT_MIN , curr=0;
     for(int i=0;i<nums.size();i++){
        curr+=nums[i];
        max_sum=fmax(curr,max_sum);
        curr=fmax(0,curr);

     }
     return max_sum;
    }
};