class Solution {
public:
    int maximumCount(vector<int>& nums) {
        long long pos = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        long long neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        pos = nums.size()-pos;

        return max(pos,neg);
    }
};