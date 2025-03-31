class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>v;
        for(int i = 0 ; i < weights.size() - 1 ; i++){
            v.push_back(weights[i] + weights[i+1]);
        }
        sort(v.begin() , v.end());
        int c = k - 1;

        long long mini = weights[0] + weights.back();
        for(int i = 0 ; i < c ; i++){
            mini += v[i];
        }

        long long maxi = weights[0] + weights.back();
        for(int i = v.size() - c; i < v.size(); i++){
            maxi += v[i];
        }

        return maxi - mini;
    }
};