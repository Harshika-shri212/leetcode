class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.size() == 0) return 0;
        int m = 0;
        int l = 0;
        int r = 0;
        map<char , int> mp;
        

        while(r < s.size()){
            if(mp.find(s[r]) == mp.end() || mp[s[r]] < l){
                m = max(m , r-l+1);
                mp[s[r]] = r;
                r += 1;
            }
            else{
                l = mp[s[r]] + 1;
            }
        }

        return m;
    }
};