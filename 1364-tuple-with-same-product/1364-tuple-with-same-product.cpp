class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int , int> mp;
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                mp[nums[i] * nums[j]]+=1;
            }
        }

        c = 0;

        for(auto i: mp){
            if(i.second > 1) c += 8 * (i.second * (i.second - 1) / 2);
        }

        return c;
        
    }
};