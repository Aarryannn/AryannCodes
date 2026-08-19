class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];
            auto itr = mpp.find(temp);
            if(itr != mpp.end()) return {i, itr->second};

            mpp[nums[i]]=i;
        }

        return {};
    }
};