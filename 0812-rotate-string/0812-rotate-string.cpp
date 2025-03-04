class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string res = "";
        int n = s.size();
        while(n--){
            string f = "";
            for(int i = 0 ; i < s.size() ; i++){
                if(i == 0) f = s[i];
                else res = res + s[i];
            }
            res = res + f;
            if(res == goal) return true;
            s = res;
            res = "";
        }
        return false;
    }
};