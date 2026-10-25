class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
       unordered_map<int,vector<int>> mpp;
       for(int i = 0; i < grp.size(); i++){
        mpp[grp[i]].push_back(i); 
       }

    vector<vector<int>> ans;

    for(auto it : mpp){
        int s = it.first;
        vector<int> temp = it.second;
        for(int i = 0; i < temp.size(); i = i + s){
            vector<int> size;
            for(int j = 0; j < s; j++){
                size.push_back(temp[j+i]);
            }

            ans.push_back(size);
        }
    }
return ans;
    }
};