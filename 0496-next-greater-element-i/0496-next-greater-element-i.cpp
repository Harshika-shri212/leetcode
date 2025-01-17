class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int> mp;
        stack<int>s;
        s.push(nums2[0]);
        for (int i=1;i<nums2.size();i++){
            while(!s.empty() && nums2[i]>s.top()){
                mp[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
            mp[s.top()]=-1;
            s.pop();
        }
        for(auto i:nums1){
            res.push_back(mp[i]);
        }
        return res;
        
        
    }
};