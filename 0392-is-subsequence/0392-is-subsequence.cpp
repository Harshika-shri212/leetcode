class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return true;
        if(s.size() == 0 && t.size() != 0) return true;
        if(s.size() != 0 && t.size() == 0) return false;
        int si = 0;
        int ti = 0;
        while(si < s.size() && ti < t.size())   {
            if(s[si] == t[ti]){
                si += 1;
                ti += 1;
                if(si == s.size()) return true;
            }
            else{
                ti += 1;
            }
        }
        return false;
    }
};