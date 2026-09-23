class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a;

        for (auto &row : grid) {
            for (int val : row) {
                if ((val - grid[0][0]) % x != 0)
                    return -1;
                a.push_back(val);
            }
        }

        sort(a.begin(), a.end());

        int mid = a[a.size() / 2];
        int ans = 0;

        for (int val : a)
            ans += abs(val - mid) / x;

        return ans;
    }
};