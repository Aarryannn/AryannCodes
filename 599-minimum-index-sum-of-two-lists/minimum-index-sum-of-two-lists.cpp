class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map <string , int> mpp;
        for(int i = 0; i < list1.size(); i++){
            mpp[list1[i]] = i;
        }
        int len = 2e9;
        vector<string> ans;
        for(int i = 0; i < list2.size(); i++){
            if( mpp.count(list2[i]) ){
                int temp = i + mpp[list2[i]];
                len = min ( len, temp);
            }
        }

        for(int i = 0; i < list2.size(); i++){
            if( mpp.count(list2[i]) ){
                int temp = i + mpp[list2[i]];
                if(temp <= len) {
                    len = temp;
                    ans.push_back(list2[i]);
                }
            }
        }
return ans;
    }
};