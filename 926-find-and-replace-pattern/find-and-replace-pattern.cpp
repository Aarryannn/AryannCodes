class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (string &word : words) {
            unordered_map<char, char> mp1, mp2;
            bool ok = true;

            for (int i = 0; i < word.size(); i++) {
                if (mp1.count(word[i]) && mp1[word[i]] != pattern[i]) {
                    ok = false;
                    break;
                }

                if (mp2.count(pattern[i]) && mp2[pattern[i]] != word[i]) {
                    ok = false;
                    break;
                }

                mp1[word[i]] = pattern[i];
                mp2[pattern[i]] = word[i];
            }

            if (ok) ans.push_back(word);
        }

        return ans;
    }
};