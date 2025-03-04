class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(set<char>(s.begin() , s.end()).size() != set<char>(t.begin() , t.end()).size() ) return false;
        map<char , char>m;
        for(int i = 0 ; i < s.size() ; i++){
            char ss = s[i] , tt = t[i];
            if(m.find(ss) == m.end()){
               
                m[ss] = tt;
            }
            else{
                if (m[ss] != tt) return false;
                
            }
        }
        return true;
    }
};