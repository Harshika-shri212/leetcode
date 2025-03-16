class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        vector<int>res(n , -1);
        int k = n - 1;
        while(k >= 0){
            int l_num = abs(nums[l]);
            int r_num = abs(nums[r]);

            if(l_num > r_num){
                int sqr = l_num * l_num;
                res[k] = sqr;
                l += 1;
                k -= 1;
            }

            else{
                int sqr = r_num * r_num;
                res[k] = sqr;
                r -= 1;
                k -= 1;
            }
        }
        return res;
    }
};