class Solution {
public:
    string countAndSay(int n) {
        string stri = "1";
        for(int i = 1 ; i < n ; i++){
            string temp = "";
            int count = 1;
            for(int i = 1 ; i < stri.size() ; i++){
                if(stri[i] == stri[i-1]){
                    count += 1;
                }
                else{
                    temp += to_string(count);
                    temp += stri[i-1];
                    count = 1;
                }
            }
            temp += to_string(count);
            temp += stri.back();
            stri = temp;
        }
        return stri;
    }
};