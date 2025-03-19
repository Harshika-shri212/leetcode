class Solution {
public:
    int minOperations(vector<int>& nums) {
        int l = 0 , r = 0, m = 0;
        int n = nums.size();
        while(l < n){
            while(r < n && nums[r] != 0){
                r += 1;
            }
            l = r + 3 - 1;
            if(l < n){
                for(int i = r ; i <= l ; i++){
                    nums[i] = !nums[i];
                }
                m += 1;
            }
            else{
                break;
            }
        }
        for(int i = r ; r < n ; i++){
            if(nums[i] == 0) return -1;
        }
        return m;
    }
};