class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i : stones){
            pq.push(i);
        }
        while(pq.size() > 1){
            int fir = pq.top();
            pq.pop();
            int sec = pq.top();
            pq.pop();

            if(fir != sec){
                sec = fir - sec;
                pq.push(sec);
            }
        }

        if(pq.size() == 1) return pq.top();
        else return 0;
    }
};