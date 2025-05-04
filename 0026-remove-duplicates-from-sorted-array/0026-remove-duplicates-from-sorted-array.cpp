class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int next_pos = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[i-1]){
                nums[next_pos] = nums[i];
                next_pos += 1;
            }
        }
        return next_pos;
    }
};