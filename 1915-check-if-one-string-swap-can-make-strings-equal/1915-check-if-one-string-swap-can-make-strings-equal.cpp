class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int c = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) c+=1;
        }

        sort(s1.begin(),s1.end()) ;
        sort(s2.begin(),s2.end());
        if( (c==0 || c==2) && (s1 == s2)) return true;
        else return false;
    }
};