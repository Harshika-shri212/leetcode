class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int l = 0 , r = 0;

        while(r < m && l < n){
            if(s[r] >= g[l]){
                l += 1;
                r += 1;
            }
            else r += 1;
        }

        return l;
    }
};