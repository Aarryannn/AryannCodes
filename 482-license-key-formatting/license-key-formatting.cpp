class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        int cnt = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '-') continue;

            ans += toupper(s[i]);
            cnt++;

            if (cnt == k) {
                ans += '-';
                cnt = 0;
            }
        }

        if (!ans.empty() && ans.back() == '-')
            ans.pop_back();

        reverse(ans.begin(), ans.end());

        return ans;
    }
};