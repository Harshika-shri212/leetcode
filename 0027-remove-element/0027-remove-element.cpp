class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            while(l < nums.size()  && nums[l] != val){
                l += 1;
                
            }
            while(r >= 0 && nums[r] == val){
                r -= 1;
                
            }
            if(l < r){
                swap(nums[l] , nums[r]);
                l += 1;
                r -= 1;
            }
        }
        return l;
    }
};