class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int st = 0;
        int i = 0;
        while(i < n){
            if(st >= i){
                int cur = nums[i] + i;
                st = max(st , cur);
                i += 1;
                if (st >= n - 1) return true;
            }
            else return false;
        }
        if (st >= n - 1) return true;
        return false;
    }
};