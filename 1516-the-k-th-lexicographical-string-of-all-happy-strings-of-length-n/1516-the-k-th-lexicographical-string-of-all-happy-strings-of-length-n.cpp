class Solution {
public:
    void solve(vector<string> &res, string happy, int n, int k, vector<string> &ch) {
         if (happy.size() == n) {  
            if (find(res.begin(), res.end(), happy) == res.end()) {  
                res.push_back(happy);  
            }
            return;
        }

        for (int i = 0; i < 3; i++) {
            if (happy.empty() || happy.back() != ch[i][0]) {  
                solve(res, happy + ch[i], n, k, ch);  
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ch = {"a", "b", "c"};
        vector<string> res;
        solve(res, "", n, k, ch);  
        sort(res.begin(), res.end());
        return res.size() >= k ? res[k - 1] : "";  
    }
};
