class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next_non_zero_index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                int temp=nums[i];
                nums[i]=nums[next_non_zero_index];
                nums[next_non_zero_index]=temp;
                next_non_zero_index+=1;
            }
        }
    }
};