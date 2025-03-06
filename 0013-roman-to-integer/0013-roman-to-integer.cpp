class Solution {
public:
    int romanToInt(string s) {
        map<char , int> m = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };

        int num = 0;
        char prev;
        char cur;

        reverse(s.begin() , s.end());
        for(char i : s){
            cur = i;
            if(m[prev] > m[cur]){
                num -= m[prev];
                num += m[prev] - m[cur];
            }
            else num += m[cur];
            prev = cur;
            
        }

        return num;
    }
};