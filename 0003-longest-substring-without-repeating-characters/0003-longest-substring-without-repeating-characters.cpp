class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int m = INT_MIN;
        for(int i = 0 ; i < s.size() ; i++){
            string ss = "";
            ss += s[i];
            m = max(m , 1);
            for(int j = i + 1; j < s.size() ; j++){
                if(ss.find(s[j]) == std::string::npos){
                    ss += s[j];
                    m = max(m , (int)ss.size());
                }
                else{
                    break;
                }
            }
        }
        return m;
    }
};