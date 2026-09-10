class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string, int> mpp;
        for(int i = 0; i < list1.size(); i++){
            mpp[list1[i]] = i;
        }
        int len = 2e9;
        for(int i = 0; i < list2.size(); i++){
            if(mpp.count(list2[i])){
                len = min(len, i+ mpp[list2[i]]);
            }
        }

        for(int i = 0; i < list2.size(); i++){
            if(mpp.count(list2[i])){
                if(len == i + mpp[list2[i]]){
                    ans.push_back(list2[i]);
                }
            }
        }
return ans;

    }
};