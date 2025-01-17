class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='['){
                ss.push(i);
            }
            else{
                if(ss.empty()) return false;
                if(i==')'){
                    if(ss.top()=='(') ss.pop();
                    else return false;
                }
                if(i=='}'){
                    if(ss.top()=='{') ss.pop();
                    else return false;
                }
                if(i==']'){
                    if(ss.top()=='[') ss.pop();
                    else return false;
                }
            }
        }
        return ss.empty();
    }
};