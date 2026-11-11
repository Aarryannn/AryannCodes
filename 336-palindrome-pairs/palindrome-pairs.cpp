
class Solution {
    struct Node {
        Node* child[26] = {};
        int wordIndex = -1;
        vector<int> palList;
    };

    Node* root = new Node();

    // Precompute palindrome prefixes and suffixes in O(k)
    void getPalindromes(string& s, vector<bool>& pre, vector<bool>& suf) {
        int n = s.size();

        vector<int> d1(n), d2(n);

        // Odd length palindromes
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n &&
                   s[i - k] == s[i + k])
                k++;

            d1[i] = k;

            if (i - k + 1 == 0)
                pre[i + k] = true;

            if (i + k - 1 == n - 1)
                suf[i - k + 1] = true;

            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        // Even length palindromes
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

            while (i - k - 1 >= 0 && i + k < n &&
                   s[i - k - 1] == s[i + k])
                k++;

            d2[i] = k;

            if (k > 0 && i - k == 0)
                pre[i + k] = true;

            if (k > 0 && i + k - 1 == n - 1)
                suf[i - k] = true;

            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }

        pre[0] = true;
        suf[n] = true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<bool>> pre(words.size()), suf(words.size());

        // Build reversed-word Trie
        for (int i = 0; i < words.size(); i++) {
            string& s = words[i];
            int n = s.size();

            pre[i].assign(n + 1, false);
            suf[i].assign(n + 1, false);

            getPalindromes(s, pre[i], suf[i]);

            Node* node = root;

            for (int j = n - 1; j >= 0; j--) {
                if (pre[i][j + 1])
                    node->palList.push_back(i);

                int c = s[j] - 'a';

                if (!node->child[c])
                    node->child[c] = new Node();

                node = node->child[c];
            }

            node->wordIndex = i;
            node->palList.push_back(i);
        }

        vector<vector<int>> ans;

        // Search each original word
        for (int i = 0; i < words.size(); i++) {
            string& s = words[i];
            int n = s.size();

            Node* node = root;
            bool valid = true;

            for (int j = 0; j < n; j++) {
                if (node->wordIndex != -1 &&
                    node->wordIndex != i &&
                    suf[i][j]) {
                    ans.push_back({i, node->wordIndex});
                }

                int c = s[j] - 'a';

                if (!node->child[c]) {
                    valid = false;
                    break;
                }

                node = node->child[c];
            }

            if (valid) {
                for (int idx : node->palList) {
                    if (idx != i)
                        ans.push_back({i, idx});
                }
            }
        }

        return ans;
    }
};
