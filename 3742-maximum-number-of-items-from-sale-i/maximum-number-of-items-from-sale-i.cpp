
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = INT_MAX;

        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            mn = min(mn, item[1]);

            int factor = item[0];
            int price = item[1];

            int cnt = 0;

            for (auto &x : items) {
                if (x[0] % factor == 0) {
                    cnt++;
                }
            }

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            ans = max(ans, dp[i] + (budget - i) / mn);
        }

        return ans;
    }
};
