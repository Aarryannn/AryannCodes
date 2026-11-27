
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int target = 1; target <= 26; target++) {
            vector<int> freq(26, 0);

            int left = 0;
            int right = 0;
            int unique = 0;
            int valid = 0;

            while (right < n) {
                int x = s[right] - 'a';

                if (freq[x] == 0) unique++;
                freq[x]++;

                if (freq[x] == k) valid++;

                while (unique > target) {
                    int y = s[left] - 'a';

                    if (freq[y] == k) valid--;

                    freq[y]--;

                    if (freq[y] == 0) unique--;

                    left++;
                }

                if (unique == target && unique == valid) {
                    ans = max(ans, right - left + 1);
                }

                right++;
            }
        }

        return ans;
    }
};
