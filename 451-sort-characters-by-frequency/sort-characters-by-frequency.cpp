class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int> freq;
        for(char c : s){
            freq[c]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto &[c, count] : freq){
        pq.push({count, c});
        }

    string ans;
    while(!pq.empty()){
        for(int i = 0; i < pq.top().first; i++){
            ans.push_back(pq.top().second );
        }
        pq.pop(); 
    }
return ans;
    }
};