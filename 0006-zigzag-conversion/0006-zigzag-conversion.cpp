

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> res(numRows, string(s.size(), '\0'));

        int cross = numRows - 1;
        int n = s.size();
        int i = 0;
        int col = 0;
        int row = 0;

        while (i < n) {
            
            for (int j = 0; j < numRows && i < n; j++) {
                res[j][col] = s[i++];
            }
            col++;

            
            for (int k = 0; k < cross - 1 && i < n; k++) {
                res[numRows - 2 - k][col] = s[i++];
                col++;
            }
        }

        string ans;
        for (int r = 0; r < numRows; r++) {
            for (char c : res[r]) {
                if (c != '\0') ans += c;
            }
        }
        return ans;
    }
};
