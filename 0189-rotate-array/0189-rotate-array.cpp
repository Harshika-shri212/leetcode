class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        k = k % nums.size();
        
        int i = 0;
        int j = k;
        
        vector<int>temp(nums.size());

        for(i , j ; j < nums.size(); i++ , j++){
            temp[j] = nums[i];
        }

        for(j = 0 ; i < nums.size() ; i++ , j++){
            temp[j] = nums[i];
        }

        for(int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = temp[i];
        }
    }
};