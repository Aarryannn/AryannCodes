
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + (power[i] - power[n - 1 - i]) * nums[i]) % MOD;
        }

        return (ans + MOD) % MOD;
    }
};
