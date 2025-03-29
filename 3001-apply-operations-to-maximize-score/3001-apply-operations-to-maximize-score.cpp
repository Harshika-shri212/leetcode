class Solution {
public:
    int M = 1e9 + 7;
    long long binaryitr(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        int sz = 1e5;
        vector<int> spf(sz + 1, 0);
        for (int i = 2; i <= sz; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= sz; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        int n = nums.size();
        vector<int> arr(n), left(n), right(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int cnt = 0;
            while (x != 1) {
                int p = spf[x], f = 0;
                while (x % p == 0) {
                    x /= p;
                    f = 1;
                }
                if (f == 1) cnt++;
            }
            arr[i] = cnt;
        }
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            if (st.empty())
                left[i] = 0;
            else
                left[i] = st.top() + 1;
            st.push(i);
        }

        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if (st.empty())
                right[i] = n - 1;
            else
                right[i] = st.top() - 1;
            st.push(i);
        }

        vector<pair<int, long long>> a(n);
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) {
                a[i] = {nums[i], 1};
            } else {
                a[i] = {nums[i], (right[i] - i + 1) * 1LL * (i - left[i]) +
                                     right[i] - i + 1};
            }
        }

        sort(a.begin(), a.end(), greater<pair<int, long long>>());
        
        int ans = 1;
        for (auto it : a) {
            if (k >= it.second) {
                ans = (ans * 1LL * binaryitr(it.first, it.second)) % M;
                cout << ans << endl;
                k -= it.second;
            } else {
                ans = (ans * 1LL * binaryitr(it.first, k)) % M;
                cout << ans << endl;
                break;
            }
        }
        return ans;
    }
};