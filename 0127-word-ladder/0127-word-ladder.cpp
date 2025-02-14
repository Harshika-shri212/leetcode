class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     set<string> s;
     queue<string> q;
     int f = 0;
     for(auto i : wordList)   {
        s.insert(i);
        if(i.compare(endWord) == 0) f=1;
     }

     if(f == 0) return 0;

     q.push(beginWord);

     int level = 0 , count;

     while(!q.empty()){
        level+=1;
        count=q.size();
        while(count--){
            string curr = q.front();
            q.pop();
            

            for(int i = 0; i < curr.size(); i++){
                string temp = curr;
                for(char ch = 'a' ; ch <= 'z'; ch++){
                    temp[i] = ch;
                    if(temp.compare(curr) == 0) continue;
                    if(temp.compare(endWord) == 0) return level+1;
                    if(s.contains(temp)) q.push(temp);
                    s.erase(temp);
                }
            }
            
        }
     }
     return 0;
    }
};