class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]] = i;
        }
        vector<int>res;
        int start = 0;
        int m = 0;

        for(int i = 0 ; i < s.size(); i++){
            if(mp[s[i]] > m) m = mp[s[i]];
            if(m == i){
                res.push_back(m - start + 1);
                start = i + 1;
                m = mp[s[i+1]];
            }
        }

        return res;
    }
};