class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp(nums.size());
        int i=0, j=0;
        k=k%nums.size();

        for( i=0,j=k; j<nums.size(); i++,j++){
            temp[j]=nums[i];
        }

        for(j=0 ; i<nums.size(); i++,j++){
            temp[j]=nums[i];
        }

        for(int i=0;i<nums.size();i++){
            nums[i]=temp[i];
        }
    }
};