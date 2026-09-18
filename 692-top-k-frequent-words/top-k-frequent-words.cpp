class Solution {
public:
    struct Compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;  // smaller string gets priority

            return a.first < b.first;        // higher frequency gets priority
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(string s : words){
            mpp[s]++;
        }

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       Compare> pq;
        for(auto &it : mpp){
            pq.push({it.second,it.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};