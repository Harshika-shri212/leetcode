class Solution {
public:
    void backtrack(int start, vector<int>& mem, unordered_set<int>& se, vector<int>& arr, int& maxi) {
        if (mem.size() > 2) 
            maxi = max(maxi, (int)mem.size());

        int su = mem[mem.size() - 2] + mem[mem.size() - 1];
        if (se.find(su) == se.end()) 
            return;

        auto it = find(arr.begin() + start, arr.end(), su);
        if (it != arr.end()) {
            int index = distance(arr.begin(), it);
            mem.push_back(su);
            backtrack(index + 1, mem, se, arr, maxi);
            mem.pop_back();
        }
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int maxi = 0;
        unordered_set<int> se(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                vector<int> mem = {arr[i], arr[j]};
                backtrack(j + 1, mem, se, arr, maxi);
            }
        }
        return maxi;
    }
};
