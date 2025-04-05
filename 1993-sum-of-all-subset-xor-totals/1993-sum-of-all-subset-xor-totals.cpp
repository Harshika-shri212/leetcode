class Solution {
public:

    void f(int start , vector<int>& cur, vector<vector<int>> &res , vector<int>& nums){
        res.push_back(cur); 
        if(start == nums.size()){
            return;
        }
        for(int i = start ; i < nums.size() ; i++){
            cur.push_back(nums[i]);
            f(i+1 , cur , res , nums);
            cur.pop_back();  
        }
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>res;
        f(0,cur,res,nums);

        int tot = 0;
        for(int i = 0 ; i < res.size() ; i++){
            int x = 0;
            for(int j = 0 ; j < res[i].size(); j++){
                x ^= res[i][j];
            }
            tot += x;
        }
        return tot;
    }
};
