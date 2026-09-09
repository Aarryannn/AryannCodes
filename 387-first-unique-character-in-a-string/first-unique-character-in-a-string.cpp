class Solution {
public:
    int firstUniqChar(string s) {
        
        vector<int> freq(26,0);
        for(char c : s){
            freq[c - 'a']++;
        }
        int i = 0;
        for(char c : s){
            if(freq[c -'a'] == 1) return i;
            i++;
        }
    return -1; 
    }
};