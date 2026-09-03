class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        vector<string> words;

        string temp;

        while(ss >> temp){
            words.push_back(temp);
        }

        reverse(words.begin(), words.end());
        string ans = "";

        for(int i = 0; i < words.size(); i++){
            if(i > 0) ans += ' ';

            ans += words[i];
        }

        return ans;

    }
};