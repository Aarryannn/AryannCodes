class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i : nums){
            mpp[i]++;
        }

        int n = nums.size();
        int k = n/4;

        for(auto &it : mpp){
            if(it.second > k) return it.first;
        }

        return -1;
    }
};