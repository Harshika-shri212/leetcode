class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> m;

        for(int i = 0 ; i < nums.size() - 1 ; i ++ ){
            if( (nums[i] == nums[i+1]) && (nums[i] != 0) ){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        for(int i : nums){
            if(i != 0) m.push_back(i);
        }

        while(m.size() < nums.size()) m.push_back(0);

        return m;
    }
};