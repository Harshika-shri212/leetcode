class Solution {
public:
    int maximumSum(vector<int>& nums) {
     unordered_map<int,vector<int>> m;
     for(int i = 0; i < nums.size() ; i++)   {
        int temp = nums[i];
        int tot = 0;
        while(temp!=0){
            int rem = temp % 10;
            tot+=rem;
            temp = temp / 10;
        }
        m[tot].push_back(nums[i]);
     }

     int maxi = -1;
     
     for(auto &  i : m){
        vector<int> &v = i.second;
        if(v.size() < 2 ) continue;
        sort(v.rbegin() , v.rend());
        maxi = max(maxi , v[0]+v[1]);
     }
     return maxi;
    }
    
};