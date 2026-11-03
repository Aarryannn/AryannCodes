#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};