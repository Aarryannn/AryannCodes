class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

       int lb = lower_bound(nums.begin(),nums.end(), target) - nums.begin();
        if(lb == nums.size() || nums[lb] != target) return {};

        while(lb < nums.size() && nums[lb] == target){
                ans.push_back(lb);
                lb++;
        }


        return ans;
    }
};