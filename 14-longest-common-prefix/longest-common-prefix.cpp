class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int x = 1; x < strs.size(); x++){
            string s = strs[x];
            // match
           int idx = -1;
           int n = min(ans.length(), s.length());
            for(int i = 0; i < n; i++){
                if(s[i] != ans[i]) {
                    if(i == 0) return "";
                    idx = i-1;
                    break;
                }
            }
            if(idx == -1) ans = ans.substr(0, n);
            else{
            ans= ans.substr(0,idx+1);
            }

        }

        return ans;
    }
};