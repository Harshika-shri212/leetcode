class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i : gifts){
            pq.push(i);
        }
        while(k--){
            int t = pq.top();
            int n = floor(sqrt(t));
            pq.pop();
            pq.push(n);
        }

        long long tot = 0;
        while(!pq.empty()){
            tot += pq.top();
            pq.pop();
        }
        return tot;
    }
};