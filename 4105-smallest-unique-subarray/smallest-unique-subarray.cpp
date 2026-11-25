class Solution {
public:
    const long long mod1 = 1e9 + 7;
    const long long mod2 = 1e9 + 9;
    const long long base = 911382323;

    vector<long long> h1, h2, p1, p2;

    bool check(int len, int n) {
        unordered_map<unsigned long long, int> mp;

        for (int i = 0; i + len <= n; i++) {
            long long x = (h1[i + len] - h1[i] * p1[len] % mod1 + mod1) % mod1;
            long long y = (h2[i + len] - h2[i] * p2[len] % mod2 + mod2) % mod2;

            unsigned long long key = (x << 32) | y;
            mp[key]++;
        }

        for (auto &it : mp) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = p1[i] * base % mod1;
            p2[i + 1] = p2[i] * base % mod2;
        }

        int l = 1, r = n;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};