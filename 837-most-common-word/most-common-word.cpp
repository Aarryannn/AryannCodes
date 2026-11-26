
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> mp;

        string word = "";

        for (int i = 0; i <= paragraph.size(); i++) {
            char c = (i < paragraph.size()) ? paragraph[i] : ' ';

            if (isalpha(c)) {
                word += tolower(c);
            } 
            else {
                if (!word.empty()) {
                    if (!st.count(word)) {
                        mp[word]++;
                    }
                    word = "";
                }
            }
        }

        string ans = "";
        int maxi = 0;

        for (auto &it : mp) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};
