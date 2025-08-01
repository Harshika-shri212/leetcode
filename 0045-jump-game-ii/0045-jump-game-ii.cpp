class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0 , l = 0 , r = 0;

        while(r < n - 1){
            int f = 0;
            for(int i = l ; i <= r ; i++){
                f = max(f , i + nums[i]);
            }
            l = r + 1;
            r = f;
            jumps += 1;
        }

        return jumps;
    }
};